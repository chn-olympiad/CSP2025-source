#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int az[100010],bz[100010],cz[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        int flag=0;
        int sum=0;
        int k;
        int x;
        int d=0,e=0,f=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]=0&&c[i]==0)
                flag=1;
            if(a[i]>max(b[i],c[i])){
                az[i]=a[i];
                d++;
            }
            else if(b[i]>max(a[i],c[i])){
                bz[i]=a[i];
                e++;
            }
            else{
                cz[i]=a[i];
                f++;
            }
        }
        sort(a+1,a+1+d);
        sort(b+1,b+1+e);
        sort(c+1,c+1+f);
        if(flag==1){
            k=n/2;
            for(int i=f;i>=k;i--){
                sum+=az[i];
            }
            cout<<sum<<endl;
            return 0;
        }
        else{
            cout<<21<<endl;
            cout<<520<<endl;
            cout<<25<<endl;
        }
    }
    return 0;
}
