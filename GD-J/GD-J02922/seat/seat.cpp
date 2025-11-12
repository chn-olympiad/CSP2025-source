#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int a[410];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xl=a[1],num=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xl){
			num=i;
			break;
		}
	}
	int ii=0;
	for(int i=1;i<=m;i++){
		ii+=n;
		if(ii>=num){
			cout<<i<<" ";
			if(i%2!=0)cout<<num+n-ii;
			else cout<<n-(num+n-ii)+1;
			return 0;
		}
	}
	return 0;
}
