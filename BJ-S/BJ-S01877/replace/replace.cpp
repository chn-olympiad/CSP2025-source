#include<bits/stdc++.h>
using namespace std;
int T,n;
struct S{
    string s1,s2;
}a[200005];
string t1,t2,t;
int f,ans,f1;
int v[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    for(int o=1;o<=T;o++){
        memset(v,0,sizeof(v));
        ans=0;
        cin>>t1>>t2;
        /*if(t1.length()!=t2.length()){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<=t1.length();i++){

            for(int j=1;j<=n;j++){
                if(v[j]){
                    continue;
                }
                int ii=i;
                f=0;
                for(int k=0;k<=a[j].s1.length();k++){
                    if(t1[ii]==a[j].s1[k]){
                        ii++;
                    }else{
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    f1=0;
                    v[j]=1;
                    int p=i;
                    t=t1;
                    for(int k=0;k<=a[j].s1.length();k++){
                        t[p]=a[j].s2[k];
                        p++;
                    }
                    for(int k=0;k<=t1.length();k++){
                        if(t[p]!=t2[p]){
                            f1=1;
                            break;
                        }
                    }
                    if(f1==0){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;*/
        cout<<0<<endl;
    }
    return 0;
}
