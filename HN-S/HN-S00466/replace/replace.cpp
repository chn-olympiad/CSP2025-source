// CSP-S 2025,max epts 80, min epts 40, AFOed
// SEE YOU TOMMOROW
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, q;
unsigned long long qA[600005], qB[600005];
const int ULL = ULLONG_MAX;
struct H{
	ll ALLHa, ALLHb, DIFHa, DIFHb, START, END;
}cha[200005];
string a[200005], b[200005], A, B;
ll Hash(string A){
	unsigned long long HASH = 0;
	for(int i = 0; i < A.size(); i++) HASH = HASH * 131 + A[i];
	return HASH;
}
bool cmp(H a, H b){
	if(a.DIFHa != b.DIFHa) return a.DIFHa < b.DIFHa;
	return a.DIFHb < b.DIFHb;
}
ll oto(ll a){
	unsigned long long s = 1;
	while(a--){
		s *= 131;
	}return s;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		cha[i].ALLHa = Hash(a[i]);
		cha[i].ALLHb = Hash(b[i]);
		for(int j = 0; j < a[i].size(); j++){
			if(a[i][j] != b[i][j]){
				a[i] = a[i].substr(j);
				b[i] = b[i].substr(j);
				cha[i].START = j;
				break;
			}
		}
		for(int j = a[i].size() - 1; j >= 0; j--){
			if(a[i][j] != b[i][j]){
				cha[i].END = a[i].size() - 1 - j;
				a[i] = a[i].substr(0, j + 1);
				b[i] = b[i].substr(0, j + 1);
				break;
			}
		}
		cha[i].DIFHa = Hash(a[i]);
		cha[i].DIFHb = Hash(b[i]);
	}
	sort(cha + 1, cha + n + 1, cmp);
	for(int i = 1; i <= q; i++){
		cin >> A >> B;
		if(A.size() != B.size()){
			cout << "0\n";
		}else{
			for(int i = 1; i <= A.size(); i++){
				qA[i] = qA[i - 1] * 131 + A[i - 1];
				qB[i] = qB[i - 1] * 131 + B[i - 1];
			}
			string C = A;
			string D = B;
			ll AS = 0, AE = 0;
			for(int j = 0; j < C.size(); j++){
				if(C[j] != D[j]){
					C = C.substr(j);
					D = D.substr(j);
					AS = j;
					break;
				}
			}
			for(int j = C.size() - 1; j >= 0; j--){
				if(C[j] != D[j]){
					C = C.substr(0, j + 1);
					D = D.substr(0, j + 1);
					AE = AS + j;
					break;
				}
			}
			ll CHa = Hash(C);
			ll DHa = Hash(D);
			ll l = 0, r = n, mid = 0;
			while(l < r){
				mid = (l + r) / 2;
				if(cha[mid].DIFHa < CHa){
					l = mid + 1;
				}else r = mid;
			}
			r = n, mid = 0;
			while(l < r){
				mid = (l + r) / 2;
				if(cha[mid].DIFHb < DHa){
					l = mid + 1;
				}else r = mid;
			}
			ll ans = 0;
			while(!(cha[l].DIFHa != CHa || cha[l].DIFHb != DHa)){
				if(AS >= cha[l].START && 
				(qA[AE + cha[l].END + 1] - qA[AS - cha[l].START] * oto(AE + cha[l].END + 1 - AS - cha[l].START))
				 == cha[l].ALLHa
				&& 
				(qB[AE + cha[l].END + 1] - qB[AS - cha[l].START] * oto(AE + cha[l].END + 1 - AS - cha[l].START))  
				 == cha[l].ALLHb){
					ans++;
				}
				l++;
			}cout << ans << '\n';
		}
	}
	return 0;
}
//È¼¾¡£¬´ËÉí£¡ 
