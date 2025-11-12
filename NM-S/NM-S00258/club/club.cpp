#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
		return a>b;
}
int a[300005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,t,res=0;
	cin>>t;
	for(int i=1;i<=t;i++){
			cin>>n;
			for(int j=1;j<=3*n;j++) cin>>a[j];
	}
	sort(a+1,a+1+3*n,cmp);
	for(int i=1;i<=n;i++) res+=a[i];
	cout<<res;
	return 0;
}
/*
1
4
4 2 1
3 2 4S
5 3 4
3 5 1
*/
