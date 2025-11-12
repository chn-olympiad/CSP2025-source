#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int b[N];
int n;
int ans;
/*
5
2 2 3 8 10

*/
void fun(int x,int k,int sum,int ma,int m){
	if(k==m){
		if(sum>ma*2){
			ans++;
		}
		return ;
	}
	if(k>m)return ;
	for(int i=x+1;i<=n;i++){
		fun(i,k+1,sum+a[i],a[i],m);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		fun(0,0,0,0,i);
		//cout<<ans<<endl;
	}
	cout<<ans;
	
	return 0;
}
