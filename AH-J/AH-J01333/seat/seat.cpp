#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            if(i%n==0){
                if((i/n)%2==1){
                    cout<<i/n<<" "<<n;
                }else{
                    cout<<i/n<<" "<<1;
                }
            }else{
                if((i/n)%2==0){
                    cout<<i/n+1<<" "<<i%n;
                }else{
                    cout<<i/n+1<<" "<<n-(i%n)+1;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
