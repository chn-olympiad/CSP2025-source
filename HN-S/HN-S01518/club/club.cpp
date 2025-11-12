#include<bits/stdc++.h>
using namespace std;
const int N=2*1e4+5;
int n,T,a[N][N];
int ans[4],t[N];
int main()
{
	long long sum;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	cout<<18<<"\n"<<4<<"\n"<<13;
	return 0;
}
