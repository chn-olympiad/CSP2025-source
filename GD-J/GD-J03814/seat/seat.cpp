#include<bits/stdc++.h>
using namespace std;
const int N=150;
int n,m;
int a[N],tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tmp=a[1];
	sort(a+1,a+n*m+1);
	int pos=lower_bound(a+1,a+n*m+1,tmp)-a;
	pos=n*m-pos+1;
	int ans1=(pos-1)/n+1,ans2;
	if(ans1%2==1) ans2=(pos-1)%n+1;
	else ans2=n-((pos-1)%n);
	cout<<ans1<<" "<<ans2;
	return 0;
}
