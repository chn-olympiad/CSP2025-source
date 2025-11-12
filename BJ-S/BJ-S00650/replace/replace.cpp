#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct node{
    string s1,s2;
    int lens;
}a[MAXN];
int dif[2005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        a[i].lens=a[i].s1.size();
    }
    string t1,t2;
    int cnt,num;
    long long ans;
    while(Q--){
        cin>>t1>>t2;
        int m=t1.size();
        cnt=0,ans=0;
        for(int i=0;i<m;i++){
            dif[i]=0;
            if(t1[i]!=t2[i]) dif[i]=1,cnt++;;
        }bool flag;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m-a[i].lens+1;j++){
                flag=1,num=0;
                for(int k=j;k<=j+a[i].lens-1;k++){
                    if(t1[k]!=a[i].s1[k-j]){
                        flag=0;
                        break;
                    }
                    if(dif[k]==1&&t2[k]!=a[i].s2[k-j]){
                        flag=0;
                        break;
                    }
                    num+=dif[k];
                }
                if(flag==1&&num==cnt){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
