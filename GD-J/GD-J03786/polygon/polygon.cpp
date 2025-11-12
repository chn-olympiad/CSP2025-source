#include <bits/stdc++.h>
using namespace std;
const int maxn=5000+10;
int a[maxn],f[maxn][maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=3;i++){
		int x=1;
		for(int i=n;i>1;i--){
			x=x*(x-1);
		}
		sum+=x;
	}
	cout<<sum;
	return 0;
}
