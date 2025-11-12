#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num;
    cin>>n>>m;
    num=n*m;
    int marks[num];
    for(int i=0;i<num;i++){
        cin>>marks[i];
    }
    int xr=marks[0];
    sort(marks,marks+num,greater<int>());
    for(int i=0;i<num;i++){
        if(marks[i]==xr){
            int position=i+1;
            if(position%m>0){
                cout<<position/m+1<<" ";
                if((position/m+1)%2==1){
                    cout<<position%m;
                }else{
                    cout<<m+1-(position%m);
                }
            }
            else{
                cout<<position/m<<" ";
                if((position/m)%2==1){
                    cout<<m;
                }else{
                    cout<<1;
                }
            }
        }
    }
    return 0;
}