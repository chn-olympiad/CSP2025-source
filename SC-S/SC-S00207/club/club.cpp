#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h=0,max2=0;
	int b[3]{0};
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	int a[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++){
		int max1=0;
		for(int j=0;j<3;j++)
		{
			max1=max(max1,a[i][j]);
		}
		h+=max1;
	}
	for(int i=0;i<n;i++)
		max2=max(max2,b[i]);
	printf("%d",h);
	return 0;
}