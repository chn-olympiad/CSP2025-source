#include<bits/stdc++.h>
using namespace std;
int shuliang111(int number,int i){
    if(number==i){
        return 1;
    }else{
  int a=number*(number-1);
return a*shuliang111(number-1,i);
    }
}
int shuliang222(int i){
    if(i==1){
        return 1;
    }else{
return i*shuliang222(i-1);
}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int number;
cin>>number;
int total[number];
for(int i=0;i<number;i++){
    cin>>total[i];
}
vector<int> dp;
int fanganshu[number-2];
for(int i=2;i<number-2;i++){
fanganshu[i]=shuliang111(number,i)/shuliang222(i);
}
dp[0]=0;
dp[1]=0;
dp[2]=0;
for(int i=3;i<number;i++){
    for(int o=i;o<number;o++){




    }
}


return 0;
}
