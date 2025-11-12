#include<bits/stdc++.h>
//rp++
//ccf let me passed
//48181542
//Eason2010
//give up already
using namespace std;
int n,k,a[500010],s[500010],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	s[0] = 0;
	for(int i = 1;i <= n;i++)
		cin >> a[i],s[i] = s[i - 1] ^ a[i];
//	for(int i = 1;i <= n;i++)
//		cerr << s[i] << " ";
//	cerr << "\n";
	for(int l = 1;l <= n;l++){
		for(int r = l;r <= n;r++){
				if(s[r] ^ s[l - 1] == k){
					ans++;
//					cerr << l << " " << r << "\n";
					l = r + 1;
					break;
				}
		}
		
	}
	cout << ans;
	cout.flush();
	cerr.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
