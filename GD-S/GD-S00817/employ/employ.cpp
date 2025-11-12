#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[505];
int a[505];
int sum;
int ans1=1,ans2=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&c);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=0) sum++;
	}
	for(int i=2;i<=sum;i++) ans1*=i;
	for(int i=2;i<=m;i++) ans2*=i;
	printf("%d",ans1/ans2);
	return 0;
}
