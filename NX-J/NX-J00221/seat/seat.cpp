#include<bits/stdc++.h>
using namespace std;

int n,m,p,df,a[105];

bool check(int x,int y){
    return x>y;
}

int main(){
    freopen("seat4.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++){
        cin>>a[i];
    }
    df=a[1];
    sort(a+1,a+p+1,check);

    int pm;
    for(int i=1;i<=p;i++){
        if(a[i]==df){
            pm=i;
            break;
        }
    }

    int c,r;
    if(pm%n==0)
        c=pm/n;

    else
         c=pm/n+1;

    if((c)%2==0){
        if(pm%m==0)
            r=1;
        else
            r=m-(pm%m)+1;
    }
    else{
        if(pm%m==0)
            r=m;
        else
            r=pm%m;
    }

    cout<<c<<" "<<r;


    return 0;
}
