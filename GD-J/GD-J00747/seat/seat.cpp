#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	cout<<(R-1)/n+1<<' ';
	if(((R-1)/n)%2==0)cout<<(R-1)%n+1;
	else cout<<n-(R-1)%n;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
}
