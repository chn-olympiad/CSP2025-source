#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+10;
int n,a[N],p[N];
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(p[j]-p[i]>2*a[j]){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt+1;
	return 0;
}