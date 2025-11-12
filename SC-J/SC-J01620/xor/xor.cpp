#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int s=0,f=1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s*10+ch-'0';
		ch = getchar();
	}
	return s*f;
}
int n,f[500005],vis = -1;
ll a[500005],k,ans,m[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(),k = read();
	bool zo = 1;
	for(int i=1;i<=n;i++){
		a[i] = read();
		if(i==1){
			m[1] = a[1];
		}else{
			m[i] = m[i-1]^a[i];
		}
		if(a[i] != 1 && a[i] != 0){
			zo = 0;
		}
	}
	if(zo && n >= 1005){
		if(k == 1){
			for(int i=1;i<=n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
			cout << ans;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i] == 0){
					ans++;
				}
				if(a[i] == 1 && a[i+1] == 1){
					ans++;
					i++;
				}
			}
			cout << ans;
		}
		return 0;
	}
	m[0] = 0;
	f[0] = 0;
	for(int i=1;i<=n;i++){
		f[i] = f[i-1];
		for(int j=0;j<=i-1;j++){
			if((m[i]^m[j]) == k && j+1>vis){
				f[i] = max(f[i],f[i-1]+1);
				vis = i;
			}else{
				continue;
			}
		}
	}
	cout << f[n];
	return 0;
}