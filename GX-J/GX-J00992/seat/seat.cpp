#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
int nm[105][105];
int a[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int R = a[1];
    for(int i=2 ; i <= n*m ; i++){
        cin>>a[i];
    }
    sort(a+1 , a+1+n*m , cmp);
    //cout<<endl;
    for(int i=1 ; i<= n*m ; i++){
        /*cout<<endl<<endl;
        cout<<"i="<<i<<endl;
        cout<<"a[i]="<<a[i]<<endl;
        cout<<"R="<<R<<endl;*/
        if(a[i]==R){
            //cout<<"(i/n+1)%2=="<<(i/n+1)%2<<endl;
            if(i%n==0){
                //cout<<-1<<endl;
                c=i/n;
                //cout<<"c="<<c<<endl;
                r=n;
                //cout<<"r="<<r<<endl;
                break;
            }else if (((i/n)+1)%2==0){
                //cout<<0<<endl;
                c=(i/n)+1;
                //cout<<"c="<<c<<endl;
                r=(n-(i%n))+1;
                //cout<<"r="<<r<<endl;
                break;
            }else if(((i/n)+1)%2!=0){
                //cout<<1<<endl;
                c=(i/n)+1;
                //cout<<"c="<<c<<endl;
                r=i%n;
                //cout<<"r="<<r<<endl;
                break;
            }
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}