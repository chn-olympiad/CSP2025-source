#include<bits/stdc++.h>
using namespace std;

int n,m,a[110];
int pm,xa,zw,chu;

bool cmp(int a1,int a2){
    return a1>a2;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i];
    }
    xa=a[1];
    sort(a+1,a+1+(n*m),cmp);
    for(int i=1;i<=(n*m);i++){
        if(a[i]==xa){
            pm=i;
        }
    }
    chu=pm/n;
    if(pm%n!=0){
        chu++;
        if(chu%2==0){
            cout<<chu<<' '<<n-pm%n+1<<endl;
        }
        else{
            cout<<chu<<' '<<pm%n<<endl;
        }
    }
    else if(pm%n==0){
        if(chu%2==0){
            cout<<chu<<' '<<1<<endl;
        }
        else{
            cout<<chu<<' '<<n<<endl;
        }
    }
}
