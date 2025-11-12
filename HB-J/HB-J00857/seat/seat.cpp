#include<bits/stdc++.h>
using namespace std;
int n,m;
int grade[150];
int grar;
int mapp[13][13];
bool cmp(int a,int b){
      return a>b;
}
int main(){
      freopen("seat.in","r",stdin);
      freopen("seat.out","w",stdout);
      ios::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      cin>>n>>m;
      int tott=n*m;
      for(int i=0;i<tott;i++){
            cin>>grade[i];
      }
      grar=grade[0];
      sort(grade,grade+tott,cmp);
      if(n%2==0){
            int flag=0;
            for(int i=0;i<n;i+=2){
                  for(int j=0;j<m;j++){
                        mapp[i][j]=grade[flag];
                        flag++;
                  }
                  for(int j=m-1;j>=0;j--){
                        mapp[i+1][j]=grade[flag];
                        flag++;
                  }
            }
      }
      else{
            int flag=0;
            for(int i=0;i<n-1;i+=2){
                  for(int j=0;j<m;j++){
                        mapp[i][j]=grade[flag];
                        flag++;
                  }
                  for(int j=m-1;j>=0;j--){
                        mapp[i+1][j]=grade[flag];
                        flag++;
                  }
            }
            for(int j=0;j<m;j++){
                        mapp[n-1][j]=grade[flag];
                        flag++;
            }
      }
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mapp[i][j]==grar){
                        cout<<i+1<<" "<<j+1<<endl;
                        return 0;
                }
            }
      }
      return 0;
}