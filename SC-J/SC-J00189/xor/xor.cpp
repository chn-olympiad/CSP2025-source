#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int ans=a[l];
			for(int i=l+1;i<=r;i++) ans+=ans^a[i];
			if(ans==k) cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}