#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)k=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
		}
	}
	int x=k/n,y=k%n;
	if(y!=0){
		if(x%2==0){
			cout<<x+1<<" "<<y;
			return 0;
		}
		else{
			cout<<x+1<<" "<<n-y+1;
			return 0;
		}
	}
	else{
		if(x%2==0){
			cout<<x<<" "<<1;
			return 0;
		}
		else{
			cout<<x<<" "<<n;
			return 0;
		}
	}
	return 0;
}
//seat
