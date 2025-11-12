#include<bits/stdc++.h>
using namespace std;
int n,m,r,ansn,ansm;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0){
		ansm=r/n;
	}else{
		ansm=r/n+1;
	}
	if(ansm%2==1){
		if(ansm==1){
			ansn=r;
		}else{
			ansn=r%n;
		}
	}else{
		ansn=n-r%n+1;
	}
	cout<<ansm<<" "<<ansn;
	return 0;
} 
