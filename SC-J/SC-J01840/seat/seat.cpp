#include<bits/stdc++.h>
using namespace std;
bool cmp1(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)cin>>a[i];
	int num=a[0];
	sort(a,a+m*n,cmp1);
	//for(int i=0;i<n*m;i++)cout<<a[i];
	for(int i=0;i<n*m;i++)
		if(a[i]==num){
			//cout<<x<<' ';
			cout<<i/n+1<<' '<<((i/n)%2==0?(i%n):(n-i%n-1))+1;
			return 0;
		}
	return 0;
}