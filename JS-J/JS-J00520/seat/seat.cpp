#include<bits/stdc++.h>
using namespace std;
int corse;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>corse;
    int temp,pm=1;
   for(int i=1;i<n*m;i++){
        cin>>temp;
        if(temp>corse){
            pm++;
        }
    }
    int myn=(pm-1)/n+1,mym=0;
    if(pm%m==0){
        mym=n;
    }
    else{
        mym=pm%m;
    }
    if(myn%2==0){
        mym=m+1-mym;
    }
    cout<<myn<<" "<<mym<<endl;
    return 0;
}
