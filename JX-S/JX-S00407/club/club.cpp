#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n!=2){
            int a[200005][5],b[200005]={0},c=0;
            int s=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<3;j++){
                    cin>>a[i][j];
                    b[i]=a[i][0];
                }
            }
            sort(b,b+n);
            for(int i=n-1;i>=0;i--){
                if(c<n/2){
                    s+=b[i];
                    c++;
                }
            }
            cout<<s<<endl;
        }
        if(n==2){
            int a[200005][5],b[200005]={0},c=0;
            int s=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<3;j++){
                    cin>>a[i][j];
                }
            }
            cout<<max(max(max(a[0][0]+a[1][1],a[0][0]+a[1][2]),max(a[0][1]+a[1][0],a[0][1]+a[1][2])),max(max(a[0][1]+a[1][0],a[0][1]+a[1][2]),max(a[0][2]+a[1][0],a[0][2]+a[1][1])))<<endl;
        }
    }
    return 0;
}
