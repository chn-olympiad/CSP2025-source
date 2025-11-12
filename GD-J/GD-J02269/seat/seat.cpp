#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,a[N],gde;
int num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	gde=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)	
		if(a[i]==gde)
			num=i;
	int c=(num%n==0 ? num/n : num/n+1);
	int mod=(num%n==0 ? n : num%n);
	int r=(c%2==0 ? n-mod+1 : mod);
	cout <<c<<" "<<r;
}
