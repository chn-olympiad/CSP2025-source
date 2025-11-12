#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int num=a[0];
    sort(a,a+n*m,cmp);
    int r,c;
    for(int i=0;i<n*m;i++){
        if(a[i]==num){
            int j=i+1;
            c=j/n;
            if(j%n!=0){
                c++;
                if(c%2==1){
                    r=j%n;
                }else{
                    r=m-j%n+1;
                }
            }else{
                if(c%2==1){
                    r=n;
                }else{
                    r=1;
                }
            }
            break;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
