#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
