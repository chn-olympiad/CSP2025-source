#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],b,flag,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			flag=i+1;
			break;
		}
	}
	c=ceil(flag*1.0/n);
	cout<<c<<" ";
	if(c%2==1){
		if(flag%n==0){
			cout<<n;
			return 0;
		}
		cout<<flag%n;
	}else{
		if(flag%n==0){
			cout<<1;
			return 0;
		}
		cout<<n+1-flag%n;
	}
	return 0;
}