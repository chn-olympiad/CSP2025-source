#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int n,m,num=0;
    cin>>n>>m;
    int z=n*m;
    for(int i=1;i<=z;i++){
        cin>>a[i];
    }
    for(int i=1;i<=z;i++){
        if(a[i]>a[1]){
            num++;
        }
    }
    if((num+1)%n==0&&((num+1)/n)%2==0){
        cout<<(num+1)/n<<" "<<1;
    }else if((num+1)%n==0&&((num+1)/n)%2!=0){
        cout<<(num+1)%n<<" "<<n;
    }else if((num+1)%n!=0&&((num+1)/n)%2==0){
        cout<<(num+1)/n+1<<" "<<(num+1)%n;
    }else if((num+1)%n!=0&&((num+1)/n)%2!=0){
        cout<<(num+1)/n+1<<" "<<m-((num+1)/n%2)+1;
    }
    return 0;
}
