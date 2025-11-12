#include<bits/stdc++.h>
using namespace std;
long long a[101],n,m,a1,a2;
bool cmp(long long s1,long long s2){
	return s1>s2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
		cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
		if(a[i]==a1){
			a1=i;
			break;
		}
	for(long long i=1;i<=m;i++)
		if(i%2)
			for(long long j=1;j<=n;j++){
				a2++;
				if(a2==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		else
			for(long long j=n;j>=1;j--){
				a2++;
				if(a2==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
	return 0;
}
