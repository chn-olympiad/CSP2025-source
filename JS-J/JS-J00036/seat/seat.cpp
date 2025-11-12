#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct peo{
    int sco,poi;
};
int n,m,a[13][13];
peo ren[110];
bool mycmp(peo s,peo t){
    return s.sco>t.sco;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>ren[i].sco;
        ren[i].poi=i;
    }
    sort(ren+1,ren+1+(n*m),mycmp);
    int sum=1,x=0,y=1;
    while(1){

        if(y%2==1){
            if(x==n) y++;
            else x++;
        }
        else if(y%2==0){
            if(x==1) y++;
            else x--;
        }


        if(ren[sum].poi==1){
            cout<<y<<" "<<x<<endl;
            break;
        }
        //cout<<x<<" "<<y<<" "<<ren[sum].poi<<ren[sum].sco<<endl;
        sum++;
    }
    return 0;
}
