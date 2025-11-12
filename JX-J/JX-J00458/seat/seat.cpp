#include<bits/stdc++.h>
using namespace std;
int cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s,top,qn,qm;
    int m,n;
    int a[110]={};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m,cmp);

    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            top=i;
            if(i%n==0){
                qm=i/n;
            }
            else{
                qm=i/n+1;
            }
            break;
        }
    }
    if(qm%2==0){
        qn=(n+1-(top%n));
    }
    else{
        if(top%n==0){
            qn=n;
        }
        else{
            qn=top%n;
        }
    }
    cout<<qm<<' '<<qn;
    return 0;
}
