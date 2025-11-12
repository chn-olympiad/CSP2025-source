#include<bits/stdc++.h>
using namespace std;
struct node{
  int sum;
  int id;
} num[100001];
bool cmp(node a,node b){
  return a.sum>b.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n*m;i++) {cin>>num[i].sum;num[i].id=i;}
 sort(num+1,num+1+n*m,cmp);
 for(int i=1;i<=n*m;i++){
  if(num[i].id==1){
    int h,l;
    if(i%n==0) l=i/n;
    else l=i/n+1;
    if(l%2==1) {
     if(i%n!=0)  h=i%n;
     else  h=n;
    }
    else{
    if(i%n!=0)  h=n-i%n+1;
     else  h=1;
    }
    cout<<l<<" "<<h;
  } }
 fclose(stdin);
 fclose(stdout);
 return 0;
}

