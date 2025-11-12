#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],f[501],n0=0;
char ss[501];
bool s[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",ss+1);
	for(int i=1;i<=n;i++){
		s[i]=ss[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]){
			n0++;
		}
	}
	long long sum=1,sum2=1;
	for(int i=2;i<=n0;i++)
		sum*=i,sum%=998244353;
	for(int i=2;i<=n-n0;i++)
		sum2*=i,sum2%=998244353;
	sum*=sum2,sum%=998244353;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
