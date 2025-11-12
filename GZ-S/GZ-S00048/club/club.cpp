//GZ-S00048 刘奂显 都匀市第三中学 
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int ans=0;
	for (int i = 1; i <= n; i++){
		int a1,a2,a3;
		scanf("%d%d%d", &a1, &a2, &a3);
		ans+=a1+=a2+=a3;
	}
	printf("%d",ans/2);
	return 0;
}

