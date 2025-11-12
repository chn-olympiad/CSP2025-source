#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
return x>y;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[1000]={0};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+n*m,cmp);
    for(int i=n*m+1;i>=1;i--){
        int cy1=0;
        int cy2=0;
        if(a[i]==k){
            cy1+=i/n;
            cy2+=i%n;
            if(cy2==1&&++cy1%2==0) cy2=n;
            else if(cy2==0&&(i-i%n)*2) cy2=n;
            else if(cy2==1&&i<=2) cy2=n;
            cout<<cy1<<" "<<cy2;
            break;
        }

    }





return 0;
}
