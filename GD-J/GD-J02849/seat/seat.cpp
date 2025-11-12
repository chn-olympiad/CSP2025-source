#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=105;
int n,m,a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	cnt=a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1);
	int cc=n*m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[cc--]==cnt){
				printf("%d %d",i,j);
				return 0;
			}
		}
		i++;
		if(i>m) return 0;
		for(int j=n;j>=1;j--){
			if(a[cc--]==cnt){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}


