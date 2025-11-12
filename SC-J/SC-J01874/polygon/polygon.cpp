#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353; 
int a[100005],b;
int c[100005]; 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++) cin>>a[i];
	sort(a+1,a+b+1);
	int c,d,e=0;
	for(int i=1;i<=b;i++){
		c=a[i];
		d=1;
		for(int j=i+1;j<=b;j++){
			c+=a[j];
			d++;
			if(c>a[j]*2&&d>=3) e++;
			e%=mod;
		}
	}
	cout<<e;
	return 0;
	fclose(stdin);
	fclose(stdout);
}