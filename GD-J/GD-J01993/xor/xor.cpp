#include <bits/stdc++.h>
using namespace std;
int n,a[500010],as=0;
long long k,h=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		h=h^a[i];
		if(h==k){
			h=0;
			as++;
		}
	}
	cout<<as;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
