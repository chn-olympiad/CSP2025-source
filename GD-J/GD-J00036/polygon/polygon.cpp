#include <bits/stdc++.h> 
using namespace std;
int a[100005],pre[100005];
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	
	return 0;	
}
