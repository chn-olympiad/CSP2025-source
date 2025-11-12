#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],num[1000],numb[1000];
bool f[1005];
string s;
long long sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		num[c[i]]++;
	}
	for(int i=n;i>=1;i--){
		numb[i]=numb[i+1]+num[i];
	}
	if(n-num[0]<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-num[0];i++){
		sum=sum*n%998244353;
	}
	int t=m;
	for(int i=1;i<=n;i++){
		if(t-num[i]>=m)
			sum=sum*numb[i]%998244353;
		t-=num[i];
	}
	cout<<sum;
	return 0;
}
