#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const static int A=1000;
int point[A];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,vis;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>point[i];
		if(i==1){
			vis=point[i];
		}
	}
	sort(point+1,point+n*m+1,cmp);
	int r=0;
	for(int i=1;i<=n*m;i++){
		if(point[i]==vis){
			r=i;
			break;
		}
		continue;
	}
	int rno=ceil(1.0*r/n);
	int rline=0;
	if(rno%2==1){
		if(r%n==0){
			rline=n;
		}
		else{
			rline=r%n;
		}
	}
	if(rno%2==0){
		if(r%n==0){
			rline=1;
		}
		else{
			rline=n-r%n+1;
		}
	}
	cout<<rno<<" "<<rline<<endl;
	return 0;
}
