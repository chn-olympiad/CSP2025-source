#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,l,r;
struct p{
    int num,id;
}a[105];
bool cmp(p x,p y){
    return x.num>y.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].num;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            if(i%n!=0){
                l=i/n+1;
            }else{
                l=i/n;
            }
            if(l%2==0){
                r=n-i%n+1;
            }else{
                if(i%n!=0){
                    r=i%n;
                }else{
                    r=n;
                }
            }
            cout<<l<<" "<<r;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
