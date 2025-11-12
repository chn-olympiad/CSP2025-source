#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned short n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<(a[1]+a[2]>a[3]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//骗分盗走1~3测试点的4*3=12分，再见。 
