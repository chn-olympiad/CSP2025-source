#include<iostream>
#include<algorithm>
using namespace std;

int a[200010];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int x=a[0];
	sort(a,a+n*m,greater<int>());
	int fl=0;
	for(int i=0;i<n*m;i++)if(a[i]==x)fl=i;
	if((fl/n)&1)cout<<fl/n+1<<" "<<n-fl%n;
	else cout<<fl/n+1<<" "<<fl%n+1;
}
