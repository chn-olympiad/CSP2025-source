#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145],Map[11][45],b=n*m,flag=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++) cin>>a[i];
	int ming=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
		if(a[i]==ming){
			ming=n*m-i;
			break;
		}
	int ans = n-(m*n-ming)%n;
	cout<<((ming-1)/n+1)<<" "<<ans;
	return 0;	
}
