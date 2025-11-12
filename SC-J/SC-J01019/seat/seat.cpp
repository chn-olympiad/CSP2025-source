#include<bits/stdc++.h>
using namespace std;
long long a[105],b[12][12];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long n,m;
	cin>>n>>m;
	long long many=n*m;
	for(int i=1;i<=many;i++)cin>>a[i];
	long long x=a[1];
	sort(a+1,a+many+1,cmp);
	for(int i=1;i<=many;i++) if(a[i]==x) x=i;
	if((n*2+1)/x==0){
		cout<<n-(x%n)+1<<" "<<x/n;
	}else{
		cout<<x%n+1<<" "<<x/n+1;
	}
	return 0;
}