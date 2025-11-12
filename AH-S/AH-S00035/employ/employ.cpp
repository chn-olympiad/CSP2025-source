#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s[510],c[510],b=0,sum=0;
	int f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i]==0&&f>c[i])f++;
			if(f==c[i])f++;
		}cout<<n-f;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0)f++;
		else if(s[i]==1)b++;
		if(b>=m)sum++;
		if(f>=c[i])f++;
	}cout<<sum%998244353;
	return 0;
}
