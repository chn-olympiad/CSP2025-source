#include<bits/stdc++.h>
using namespace std;
int a[1009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+sum,cmp);
	int cnt=0;
	for(int i=1;i<=sum;i++){
		cnt++;
		if(a[i]==ans) break;
	}
	int c=0,r=0;
	int flag;
	if(cnt%n==0){
		flag=cnt/n;
	}else flag=cnt/n+1;
	//判断是下走还是上走,ji下ou上 
	if(flag%2==1){
		if(cnt%n==0){
			c=cnt/n;
			r=n;
		}else{
			c=(cnt/n)+1;
			r=cnt%n;
		}
	}else{
		if(cnt%n==0){
			c=cnt/n;
			r=1;
		}else{
			c=(cnt/n)+1;
			r=n-(cnt%n)+1;
		}
	}cout<<c<<" "<<r<<endl;
	return 0;
} 
