#include<bits/stdc++.h>
using namespace std;
struct clu{
    int a1,a2,a3;
}a[1000000];
bool cmp(clu x,clu y){
    return x.a1>y.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        int s=0;
        cin>>n;
        int b1=n/2,b2=n/2,b3=n/2;
        for(int j=0;j<n;j++){
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
        }
        sort(a,a+n,cmp);
        for(int j=0;j<n;j++){
            if(a[j].a1>a[j].a2&&a[j].a1>a[j].a3&&b1>0){
                b1--;
                s+=a[j].a1;
            }
            else if(a[j].a2>a[j].a3&&b2>0){
                b2--;
                s+=a[j].a2;
            }
            else{
                if(b3>0){
                    b3--;
                    s+=a[j].a3;
                }
                else if(b1>0){
                    if(a[j].a1>a[j].a2||b2==0){
                        b1--;
                        s+=a[j].a1;
                    }
                    else{
                        b2--;
                        s+=a[j].a2;
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
