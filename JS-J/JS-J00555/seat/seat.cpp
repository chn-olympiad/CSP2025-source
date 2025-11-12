#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],ai,num,mm;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int N=m*n;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        if(i==1) ai=a[i];
    }
    sort(a+1,a+1+N,cmp);
    for(int i=1;i<=N;i++){
        if(a[i]==ai) num=i;
    }
    if(num%m==0) mm=num/m;
    else mm=num/m+1;
    if(mm%2==1){
        if(num%n==0){
            cout<<(num/n)<<" "<<n<<'\n';
            return 0;
        }
        else cout<<(num/n)+1<<" "<<(num%n)<<'\n';
    }
    else{
        if(num%n==0){
             cout<<(num/n)<<" "<<1<<'\n';
        }
        else cout<<(num/n)+1<<" "<<n-(num%n)+1<<'\n';
    }
    return 0;
}
