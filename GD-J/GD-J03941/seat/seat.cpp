#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+1+n*m);
	int cnt=-1;
	for(int i=1;i<=n*m;i++)
		if(a[i]==r){
			cnt=n*m-i+1;
			break;
		}
	int ans1=cnt/n,ans2;
	if(ans1*n<cnt) ans1++;
	if(ans1%2!=0) ans2=cnt-(ans1-1)*n; 
	else ans2=n-(cnt-(ans1-1)*n)+1;
	cout<<ans1<<" "<<ans2;		
	return 0;
} 
