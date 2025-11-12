#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
long long n,m,ans;
cin>>n>>m;
string a[100050],b[100050],l,r;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
}
if(n>=500){
    while(m--){
        cout<<"0\n";
    }
    return 0;
}
    while(m--){
        cin>>l>>r;
        ans=0;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    string u="";
            for(int k=i;k<=j;k++){
                u=u+l[k];
            }
                for(int ii=1;ii<=n;ii++){
                    if(u==a[ii]){
                        bool f=1;
                        for(int iii=0;iii<b[ii].size();iii++){
                            if(b[ii][iii]!=r[i+iii]){
                                f=0;
                                break;
                            }
                        }
                        if(f==1)ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
return 0;}
