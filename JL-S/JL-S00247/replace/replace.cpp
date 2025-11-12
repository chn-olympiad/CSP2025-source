#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
map<string,int> to;
map<pair<string,int>,string> str;
int check(string a,string b){
    int l1=a.size(),l2=b.size(),ans=0;
    for(int i=0;i<l1;i++){
        for(int l=1;l<=l1-i;l++){
            string temp="",x=a;
            for(int k=1;k<=l;k++) temp+=a[i+k-1];
            if(to[temp]){
                for(int k=1;k<=to[temp];k++){
                    for(int j=i;j<=i+l-1;j++) x[j]=str[{temp,k}][j-i];
                    //cout<<str[{temp,k}]<<'\n';
                    if(x==b) ans++;
                    //cout<<str[{a,k}]<<'\n';
                }
            }
        }
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        bool ok=1;
        for(int j=1;j<=to[a];j++) if(str[{a,j}]==b) ok=0;
        if(ok) str[{a,++to[a]}]=b;
    }
    string x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        printf("%d\n",check(x,y));
    }
    return 0;
}
