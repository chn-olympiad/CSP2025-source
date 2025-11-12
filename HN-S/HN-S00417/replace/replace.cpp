
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
const int kMaxN = 200005,kMaxM = 5000005,mod = 1e9 + 7,base1 = 31,base2 = 37;
string a[kMaxN],b[kMaxN];
int l[kMaxN],r[kMaxN];
int e[kMaxN][2];
int hash1[kMaxM],hash2[kMaxM],qpow1[kMaxM],qpow2[kMaxM];
int Hash1[kMaxM],Hash2[kMaxM];
int Hash11[kMaxM],Hash22[kMaxM];
int get(int l,int r){
	int e = Hash11[r];
//	cout<< l <<  "!" << r << " "  << e << '\n';
	if(l != 0){
		e = (e - Hash11[l-1]*qpow1[r-l+1]%mod+mod) %mod;
	}
	return e;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r"stdin);
	freopen("replace.out","w",stdut);
	int n,q;
	cin >> n >> q;
	qpow1[0] = qpow2[0] = 1;
	for(int i = 1;i < kMaxM;i++){
		qpow1[i] = (qpow1[i-1] * base1) %mod;
		qpow2[i] = (qpow2[i-1] * base2) %mod;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		l[i] = -1,r[i] = -1;
		for(int j =0;j < a[i].size();j++){
			hash1[i] = (hash1[i] * base1 + (int)(a[i][j] - 'a' + 1) )% mod;
			hash2[i] = (hash2[i] * base2 + (int)(a[i][j]- 'a' + 1) )% mod;
			if(a[i][j]!= b[i][j]){
				if(l[i] == -1) l[i] = j;
				r[i] = j;
			}
		}
	}
	while(q--){
		int num = 0;
		string x,y;
		cin >> x >> y;
		int ll = -1,rr = -1;
		int p = 0,q=0;
		for(int j = 0;j < x.size();j++){
			p = (p*base1 + (int)(x[j] - 'a'+1) ) % mod;
			q = (q*base2 + (int)(x[j] - 'a'+1) ) % mod;
		//	cout << p << " " << q << '\n';
			Hash11[j] = p,Hash22[j] = q;
		}
		for(int j =0;j < x.size();j++){
			if(x[j]!= y[j]){
				if(ll == -1) ll = j;
				rr = j;
			}
		}
		int sizz = x.size();
		for(int i = 1;i <= n;i++){
			int siz = a[i].size();
		//	cout << x << " " << y << " " << ll << " " << rr << " " << a[i] << " " << b[i] << " " << l[i] << " " << r[i] << endl;
			if(r[i] - l[i] == rr - ll){
				if(r[i] == -1){
					num++;
				}else{
					if(ll >= l[i]&&siz - r[i]<= sizz -rr){
			//			cout << ll-l[i] << " " << ll-l[i]+siz-1<< " " <<get(ll - l[i],ll-l[i] + siz -1)  <<" " << hash1[i] << '\n';
						if(get(ll - l[i],ll-l[i] + siz -1) == hash1[i]){
							num++;
						}
					}
				}
			}
		}
		cout << num<< '\n';
	}
	return 0;
}
