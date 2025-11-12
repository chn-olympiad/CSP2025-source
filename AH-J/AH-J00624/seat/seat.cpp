#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			r=a[i];
		}
	}
	sort(a,a+(n*m),cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	int r1=r/n;
	r1++;
	r=r%n;
	cout<<r1<<" ";
	if(r1%2==1){
		cout<<r+1;
	}else{
		cout<<n-r;
	}
	return 0;
}
