#include<bits/stdc++.h>
using namespace std;
const int N=12;
int n,m,a[N*N];
int l,r,s,sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=1;
	s=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		if((l==n&&sum==1)||(l==1&&sum==-1)){
			r++;
			sum=-sum;
		}
		else{
			l+=sum;
		}
		if(a[i]==s){
			cout<<r<<" "<<l;
			return 0;
		}
	}
	return 0;
}
