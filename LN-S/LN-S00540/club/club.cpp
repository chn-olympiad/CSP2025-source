#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct l{
    int a,b,c;
};
bool cmp(l a,l b){
    return a.a>b.a;
}
l arr[3*N];
bool flag[N];
int flag2[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        memset(arr,0,sizeof arr);
        memset(flag,0,sizeof flag);
        memset(flag2,0,sizeof flag2);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[3*i+j].a;
                arr[3*i+j].b=i;
                arr[3*i+j].c=j;
            }
        }
        sort(arr,arr+3*n,cmp);
        for(int i=0;i<3*n;i++){
            if(!flag[arr[i].b]&&flag2[arr[i].c]+1<=n/2){
                sum+=arr[i].a;
                flag[arr[i].b]=1;
                flag2[arr[i].c]++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}