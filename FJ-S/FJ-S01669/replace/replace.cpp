#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n,T,cnt[N],l[N],r[N];
string a[N],b[N],str1,str2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> T;
	bool flag1 = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		int u = 0,v = 0;
		for(int j = 0;j < a[i].length();j++){
			if(a[i][j] != 'a' && a[i][j] != 'b' && b[i][j] != 'a' && b[i][j] != 'b'){
				flag1 = false;
				break;
			}
			if(a[i][j] == 'b'){
				if(u != 0){
					flag1 = false;
					break;
				}
				u = j;
				l[i] = j;
			}
			if(b[i][j] == 'b'){
				if(v != 0){
					flag1 = false;
					break;
				}
				v = j;
				r[i] = j;
			}
		}
		cnt[i] = v - u;
	}
	while(T--){
		cin >> str1 >> str2;
		if(flag1){
			int u = 0,v = 0,ans = 0;
			for(int i = 0;i < str1.length();i++){
				if(str1[i] == 'b'){
					u = i;
					break;
				}
			}
			for(int i = 0;i < str2.length();i++){
				if(str2[i] == 'b'){
					v = i;
					break;
				}
			}
			for(int i = 1;i <= n;i++){
				if(u + cnt[i] == v && u >= l[i] && u <= str1.length() - a[i].length() + l[i] + 1 && v >= r[i] && v <= str2.length() - b[i].length() + r[i] + 1){
					ans++;
				}
			}
			cout << ans << endl;
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			string x = a[i],y = b[i];
			int len = x.length();
			for(int j = 0;j < str1.length() - len + 1;j++){
				if(str1[j] == x[0]){
					bool flag = true;
					for(int k = j + 1;k <= j + len - 1;k++){
						if(str1[k] != x[k - j]){
							flag = false;
							break;
						}
					}
					if(flag){
						string str3 = str1;
						for(int k = j;k <= j + len - 1;k++){
							str3[k] = y[k - j];
						}
						if(str3 == str2){
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
2 5
aabaa
abaaa
aaaba
aaaab
aaaaab
aaaaba
*/
