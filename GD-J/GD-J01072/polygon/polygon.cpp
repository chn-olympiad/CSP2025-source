#include<bits/stdc++.h>
using namespace std;
int m,a[10005],cnt,ma = -999;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&m);
	for(int i = 1; i <= m; i++){
		scanf("%d",&a[i]);
		cnt += a[i];
		if(a[i] > ma) ma = a[i];
	}
	if(cnt <= 2 * ma){
		printf("%d",0);
		return 0;
	}
	return 0;
}
