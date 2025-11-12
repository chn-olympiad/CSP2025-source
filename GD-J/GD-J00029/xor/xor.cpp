#include<bits/stdc++.h>
using namespace std;
long long num[500001],vis[500001];
int n;
long long k,x;
int l[500001],r[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		x = num[i];
		if(x == k){
			cnt++;
			l[cnt] = i,r[cnt] = i;
		}
		for(int j=i+1;j<=n;j++){
			x ^= num[j];
			if(x == k){
				cnt++;
				l[cnt] = i,r[cnt] = j;
			}
		}
	}
//	cout << cnt << endl; 
//	cout << l[1] << ' '<< r[1] << endl;
	long long ans = 0;
	for(int i=1;i<=cnt;i++){
		bool f = true;
		for(int j=l[i];j<=r[i];j++){
			if(vis[j] == 1){
				f = false;
				break;
			}
		}
		if(f == true){
//			cout << l[i] << ' ' << r[i] << ' ' << endl;
			ans++;
			for(int j=l[i];j<=r[i];j++){
				vis[j] = 1;
			}		
		}
	}
	cout << ans;
	return 0;	
}
