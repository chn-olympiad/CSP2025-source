#include <bits/stdc++.h> std;
using namespace std;
int n,k;
int a[500010];
int x[500010];//ͷ
int y[500010];//β 
int b;
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			x[b]=i;
			y[b]=i;
			b++;
		}
	}
	return 0;
}
