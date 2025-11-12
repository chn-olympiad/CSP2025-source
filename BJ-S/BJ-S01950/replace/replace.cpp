#include<bits/stdc++.h>
using namespace std;
struct pairs{
    string y,y1;
    int l;
}a[200100];
long long ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i].y>>a[i].y1;
        a[i].l=a[i].y.length();
    }
    string s,t;
    for(int i=1;i<=m;i++){
        ans=0;
        cin>>s>>t;
        if(s.length()!=t.length()){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            //cout<<a[i].l<<endl;
            for(int j=0;j<=s.length()-a[i].l;j++){
                if(s.substr(j,a[i].l)==a[i].y){
                    string s1=s.substr(0,j);
                    string s2=s.substr(j+a[i].l,s.length()-a[i].l);
                    string t1=s1+a[i].y1+s2;
                    if(t1==t){
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}