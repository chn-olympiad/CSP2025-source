#include<iostream>
using namespace std;

const int maxn=5*1e5+10;
int n,k;
int a[maxn+10];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;

    for(int i=0;i<n;i++)cin>>a[i];

    int ans=0;

    for(int i=0;i<n;i++){
        if(a[i]==k){
            ans++;//cout<<a[i]<<endl;
            continue;
        }else{
            int base =0;
            for(int j=i;j<n;j++){
                base+=base|a[j];
                if(base==k){
                    ans++;//cout<<a[i]<<' '<<a[j]<<endl;
                    i=j+1;
                    break;
                }
            }

        }
    }

    cout<<ans;

    return 0;
}
