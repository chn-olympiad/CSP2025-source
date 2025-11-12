#include<bits/stdc++.h>
using namespace std;
long long a[6000000],ans,k,n;
void xorn(int x){
	long long anss=a[x];
	if(x>=n){
		return;
	}
	if(anss==k){
		ans++;
		a[x]=-1;
		xorn(x+1);
	}
	else{
		bool zxy=0;
		for(long long i=x+1;i<=n;i++){
			if(a[i]==-1){
				break;
			}
			anss=anss^a[i];
			if(anss==k){
				ans++;
				for(long long j=x+1;j<=i;j++){
					a[j]=-1;
				}
				xorn(i+1);
				zxy=1;
				break;
			}
		}
		if(!zxy){
			xorn(x+1);
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		xorn(i);
	}
	cout<<ans;
	return 0;
}
