#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long n,a[N],ans;
bool l;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) l=1;
	} 
	if(n == 3){
		if(a[1]+a[2]+a[3] > max(a[3],max(a[1],a[2]))*2){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}else if(n < 3){
		cout<<0;
		return 0;
	}
	if(!l){
		int aa=1;
		for(int i=n;i>=(n-2);i--){
			aa*=i;
		}
		aa/=6;
		cout<<aa;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i;j<=n-2;j++){
			if(a[j+1]+a[j]+a[j+2] > max(a[j],max(a[j+1],a[j+2]))*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
