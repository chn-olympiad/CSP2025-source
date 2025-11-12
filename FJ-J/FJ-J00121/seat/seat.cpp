#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int tar=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int p=find(a+1,a+n*m+1,tar)-a;
	int cnt=0;
	for (int i=1;i<=m;i++){
		if (i%2){
			for (int j=1;j<=n;j++){
				cnt++;
				if (cnt==p){
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				cnt++;
				if (cnt==p){
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
