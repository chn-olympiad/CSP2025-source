#include<iostream>
#include<algorithm>
using namespace std;
int v[1000000];
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,nt=1,mt=1,ao=0;
  cin>>n>>m;
  for(int j=0;j<n*m;j++){
    cin>>v[j];
  }
  ao=v[0];
  sort(v,v+n*m);
  for(int j=n*m-1;j>=0;j--){
    if(v[j]==ao){
        cout<<nt<<' '<<mt;
        break;
    }
    if(nt%2==1){
        if(mt<n){
            mt++;
        }else{
            nt++;
        }
    }else{
        if(mt>1){
            mt--;
        }else{
            nt++;
        }
    }
  }
  return 0;
}
