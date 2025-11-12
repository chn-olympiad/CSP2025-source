#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        int p1,p2;
        cin>>s1>>s2;
        int l1=s1.size(),l2=s2.size();
        for(int j=0;j<l1;j++){
            if(s1[j]=='b'){
                p1=j+1;
                b[i]=j;
                c[i]=l1-j-1;
                break;
            }
        }
        for(int j=0;j<l2;j++){
            if(s2[j]=='b'){
                p2=j+1;
                break;
            }
        }
        a[i]=p2-p1;
    }
    for(int i=1;i<=q;i++){
        string s1,s2;
        int p1,p2,p3,p4;
        cin>>s1>>s2;
        int l1=s1.size(),l2=s2.size();
        for(int j=0;j<l1;j++){
            if(s1[j]=='b'){
                p1=j+1;
                p3=j;
                p4=l1-j-1;
                break;
            }
        }
        for(int j=0;j<l2;j++){
            if(s2[j]=='b'){
                p2=j+1;
                break;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(p2-p1==a[j]&&p3>=b[j]&&p4>=c[j])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
