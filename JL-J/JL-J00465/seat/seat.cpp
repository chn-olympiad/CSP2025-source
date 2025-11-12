#include<bits/stdc++.h>
using namespace std;
struct stu{
    int cj;
    int xr;
}a[1010];
bool cmp(stu a,stu b){
    return a.cj>b.cj;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].cj;
        a[i].xr=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int pm=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].xr==1){
            pm=i;
        }
    }
    //cout<<pm<<endl;
    if(pm/n==1&&pm<=n){
        if(pm%n==0){
            cout<<"1"<<" "<<n;
        }else{
          cout<<"1"<<" "<<pm%m;
        }
    }else{
        if((pm/n)%2==1){
            if(pm%n==0){
                cout<<pm/n+1<<" "<<1;
            }else{
                cout<<pm/n+1<<" "<<n-(pm%n)+1;
            }
        }
        if((pm/n)%2==0){
            if(pm%n==0){
                cout<<pm/n<<" "<<n;
            }else{
                cout<<pm/n+1<<" "<<pm%n;
            }

        }
    }
    return 0;
}
