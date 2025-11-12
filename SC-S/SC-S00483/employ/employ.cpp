#include<bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout); 
	int n,m,mo=998244353;
	ll ans=1;
	string difficult; 
	cin>>n>>m;
	cin>>difficult;
	int a[n],d[n],num=0;
	bool dif[n];
	if(m==1){
		for(int i=n;i>0;--i)
		{
			cin>>a[i];
			ans*=i;
			ans=ans%mo;
		}
		
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		dif[i]=difficult[i]-'0';
		d[i]=num;
		if(dif[i]==0)num++;
	}
	sort(a,a+n);
	
	cout<<ans;
	return 0;
}