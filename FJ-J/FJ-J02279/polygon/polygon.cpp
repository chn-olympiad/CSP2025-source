#include<bits/stdc++.h>
using namespace std;
long long n,a[5140];long long he,zuida;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		he+=a[i];
	}
	sort(a+1,a+n+1);
    zuida=a[n];
	if(he>zuida*2)cout<<1;
	else cout<<0;
	return 0;
}
