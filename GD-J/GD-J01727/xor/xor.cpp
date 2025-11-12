#include <bits/stdc++.h>
using namespace std;
int a[500005],xorn[500005];
bool cmp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		xorn[i]=xorn[i-1]^a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i+1;j++){
			if ((xorn[j+i-1]^xorn[j-1])==k){
				bool flag=1;
				for (int x=j;x<=j+i-1;x++){
					if (cmp[x]){
						flag=0;
						break;
					}
				}
				if (flag){
					s+=1;
					for (int x=j;x<=j+i-1;x++){
						cmp[x]=1;
					}
				}
			}
		}
	}
	cout << s;
	return 0;
}
