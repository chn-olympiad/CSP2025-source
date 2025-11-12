#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
struct peo{
    int a,b,c,cn,m1,m2,m3,cho,d;
}arr[M];
long long ve[4],k=0;
long long v[M];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(arr,0,M);
        memset(ve,0,4);
        memset(v,0,M);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i].a>>arr[i].b>>arr[i].c;
            arr[i].cn=arr[i].a+arr[i].b+arr[i].c;
            if(arr[i].a>arr[i].b){
                if(arr[i].b>arr[i].c){
                    arr[i].m1=1;
                    arr[i].m2=2;
                    arr[i].m3=3;
                }
                else if(arr[i].c>arr[i].b&&arr[i].a>arr[i].c){
                    arr[i].m1=1;
                    arr[i].m2=3;
                    arr[i].m3=2;
                }
                else{
                    arr[i].m1=3;
                    arr[i].m2=1;
                    arr[i].m3=2;
                }

            }
            if(arr[i].b>arr[i].a){
                if(arr[i].a>arr[i].c){
                    arr[i].m1=2;
                    arr[i].m2=1;
                    arr[i].m3=3;
                }
                else if(arr[i].b>arr[i].c&&arr[i].c>arr[i].a){
                    arr[i].m1=2;
                    arr[i].m2=3;
                    arr[i].m3=1;
                }
                else {
                    arr[i].m1=3;
                    arr[i].m2=2;
                    arr[i].m3=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            ve[arr[i].m1]++;
            ve[0]+=max(arr[i].a,max(arr[i].b,arr[i].c));
            arr[i].d=2*max(arr[i].a,max(arr[i].b,arr[i].c))-arr[i].cn+min(arr[i].a,min(arr[i].b,arr[i].c));
        }
        if(ve[1]>n/2){
            for(int i=1;i<=n;i++){
                if(arr[i].m1==1)v[k++]=arr[i].d;
            }
            sort(v,v+k-1,cmp);
            for(int i=0;i<k-n/2;i++)ve[0]-=v[i];
        }
        if(ve[2]>n/2){
            for(int i=1;i<=n;i++){
                if(arr[i].m1==2)v[k++]=arr[i].d;
            }
            sort(v,v+k-1,cmp);
            for(int i=0;i<k-n/2;i++)ve[0]-=v[i];
        }
        if(ve[3]>n/2){
            for(int i=1;i<=n;i++){
                if(arr[i].m1==3)v[k++]=arr[i].d;
            }
            sort(v,v+k-1,cmp);
            for(int i=0;i<k-n/2;i++)ve[0]-=v[i];
        }
        cout<<ve[0];
        cout<<endl;
    }
    return 0;
}
