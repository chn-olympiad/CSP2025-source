#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++) cin>>a[i];
	int t=a[1];
	int cnt=0;
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++) {
		if(a[i]==t) {
			cnt=i;
			break;
		}
	}
	int lie=cnt/n;
	int hang=cnt%n;
	if(!hang) {
		if(lie%2) cout<<lie<<" "<<n;
		else cout<<lie<<" "<<"1";
	}
	else {
		if(lie%2) cout<<lie+1<<" "<<n-hang+1;
		else cout<<lie+1<<" "<<hang;
	}
	return 0; 
}