#include<bits/stdc++.h>
using namespace std;
struct aespa{
    int a;
    int b;
    int c;
}a[100001];
int t,sum=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int n[t];
    for(int i=0;i<t;i++){
        cin>>n[i];
        sum+=n[i];
        if(i==0){
            for(int j=0;j<n[i];j++){
                cin>>a[j].a>>a[j].b>>a[j].c;
            }
        }
        else{
            for(int j=n[i-1];j<n[i]+n[i-1];j++){
                cin>>a[j].a>>a[j].b>>a[j].c;
            }
        }
    }
    int ans[t];
    sum/=2;
    for(int i=0;i<t;i++){
        if(i==0){
            for(int j=0;j<n[i];j++){
                if(a[j].a>a[j].b && a[j].a>a[j].c){
                    ans[i]+=a[j].a;

                }
                else if(a[j].b>a[j].a && a[j].b>a[j].c){
                    ans[i]+=a[j].b;
                }
                else if(a[j].c>a[j].a && a[j].c>a[j].b){
                    ans[i]+=a[j].c;
                }
            }
        }
        else{
            for(int j=n[i-1];j<n[i]+n[i-1];j++){
                if(a[j].a>a[j].b && a[j].a>a[j].c){
                    ans[i]+=a[j].a;

                }
                else if(a[j].b>a[j].a && a[j].b>a[j].c){
                    ans[i]+=a[j].b;
                }
                else if(a[j].c>a[j].a && a[j].c>a[j].b){
                    ans[i]+=a[j].c;
                }
            }
        }
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
    return 0;
}
