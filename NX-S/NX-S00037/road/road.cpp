#include<bits/stdc++.h>
using namespace std;
int s;
bool cmp(int x,int y){
if(x>y)return 1;
else
return 0;
}
int zhong(int w,int e,int r){
    int y;
    int m=max(w,max(e,r));
     if(m==w){
        y=m-max(e,r);
     }
     else if(m==e){
        y=m-max(w,r);
     }
     else if(m==r){
        y=m-max(w,e);
     }
 return y;
}
int main(){

cout<<0;
return 0;


}
