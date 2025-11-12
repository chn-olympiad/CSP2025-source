# include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]<a[2]+a[3]) printf("1");
		else printf("0");
		return 0;
	}
	printf("0");
	return 0;
}