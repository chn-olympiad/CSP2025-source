#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}// 第六个样例是疯了吗？！！！ 
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	} 
	cout<<ans;
	return 0;
}
