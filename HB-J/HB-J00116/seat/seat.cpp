#include<bits/stdc++.h>
using namespace std;
int f[110],fs[110];
int m_,n_,seat,c_,r,a_1;
int main(){
freopen("seat3.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n_>>m_;
cin>>a_1;
f[1]=a_1;
for(int i=2;i<n_*m_+1;i++){
    cin>>f[i];
}//#

for(int j=1;j<=100;j++){
    if(f[j]>=a_1) seat++;
}
for(int c=0;1==1 ;c++){
    seat-=n_;
    if(seat<=0){
        c_=c;

        break;
    }
}

if(seat!=0){
    seat+=n_;
    if(c_%2==0){
        r=n_+1-seat;
    }
    else if(c_%2==1){
        r=seat;
    }
}
else if(c_%2==0){
    r=1;
}
else if(c_%2==1){
    r=n_;
}
cout<<c_+n_-1<<" "<<r+m_-1;

return 0;}
