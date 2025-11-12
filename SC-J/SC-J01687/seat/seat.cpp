#include<bits/stdc++.h> 
using namespace std;
priority_queue<int> pq;
int n,m,num,a,am=1,an=1;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  cin>>num;
  pq.push(num);
  for(int i=1;i<n*m;i++){
  	cin>>a;
  	pq.push(a);
  }
  while(!pq.empty()){
  	if(pq.top()==num) break;
    if(am%2==1) an++;
    else an--;
    if(an>n||an==0){
    	am++;
    	if(an>n) an=n;
    	if(an==0) an=1;
	}
	pq.pop();
  }
  cout<<am<<" "<<an;
  return 0;
}