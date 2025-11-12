#include<bits/stdc++.h>
using namespace std;
int n,a[1001000],k,c;
bool b[1001000];
int yh(int q,int e){
	if(q==e) return a[q];
	int h=a[q];
	for(int i=q+1;i<=e;i++){
		h=h^a[i];
	}
	return h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(b[i]==1) i++;
		for(int j=i;j<=n;j++){
			if(b[j]==1) j++;
			int z=yh(i,j);
			if(z==k){
				c++;
				for(int p=i;p<=j;p++) b[p]=1;
				break;
			}
		}
	}
	cout<<c;
	return 0;
}
