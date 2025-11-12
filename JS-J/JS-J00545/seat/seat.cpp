#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],key,key_data;
bool cmp(int a,int b){
    if(a<b) return false;
    return true;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>key_data;
    a[1]=key_data;
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) if(a[i]==key_data) key=i;
    int num=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(n*(i-1)+j==key){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(n*(i-1)+n-j+1==key){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
