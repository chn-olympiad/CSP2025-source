#include <bits/stdc++.h>
using namespace std;

int a[500005][50],p[50];

struct Node{
    int i,j;
}b[1000005];

bool cmp(Node x,Node y){
    return x.j<y.j;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    p[0]=1;
    for(int i=1;i<=25;i++)p[i]=p[i-1]*2;
    int n,k,M=INT_MIN,pp=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        string s="";
        if(x==0)s="0";
        while(x){
            if(x%2==0)s+='0';else s+='1';
            x/=2;
        }
        int ss=s.size();
        M=max(M,ss);
        if(i==1)for(int j=1;j<=M;j++)a[1][j]=s[j-1]-'0';
        else{
            int y;
            for(int j=1;j<=M;j++){
                if(j>s.size())y=0;else y=s[j-1]-'0';
                if(a[i-1][j]==y)a[i][j]=0;else a[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            string s="";
            for(int k=1;k<=M;k++){
                if(a[j][k]==0)s+=a[i-1][k]+'0';
                else{
                    if(a[i-1][k]==0)s+='1';else s+='0';
                }
            }
            int cnt=0;
            for(int i=0;i<s.size();i++)if(s[i]=='1')cnt+=p[i];
            if(cnt==k)b[pp].i=i,b[pp++].j=j;
        }
    }
    sort(b+1,b+pp,cmp);
    int ans=1;
    int l=b[1].j;
    for(int i=2;i<pp;i++){
        if(b[i].i>l){
            l=b[i].j;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
