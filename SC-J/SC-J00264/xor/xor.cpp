#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k){
		for(int i=1;i<=n;i++){
			if(a[i]) ans++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!a[i]) ans++;
		}
	}
	printf("%d",ans); 
	return 0;
}