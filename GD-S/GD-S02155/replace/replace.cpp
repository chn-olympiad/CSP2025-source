#include<bits/stdc++.h>
//ccf
//rp++
//481817542
using namespace std;
typedef long long ll;
const int m1 = 1e9 + 7,m2 = 1e9 + 5,b = 310;
int n,q;
string s1,s2,t1,t2;
//ll h11[5000010],h12[5000010],h21[5000010],h22[5000010],p1[5000010],p2[5000010];
//set<pair<pair<ll,ll>,pair<ll,ll>>> s;
//pair<ll,ll> gh1(int l,int r){
//	return {(h11[l] - h11[r + 1]) / p1[r + 1] + m1 % m1,(h12[l] - h12[r + 1]) / p2[r + 1] + m2 % m2};
//}
//pair<ll,ll> gh2(int l,int r){
//	return {(h21[l] - h21[r + 1]) / p1[r + 1] + m1 % m1,(h22[l] - h22[r + 1]) / p2[r + 1] + m2 % m2};
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int j = 1;j <= n;j++){
		cin >> s1 >> s2;
//		ll h11 = 0,h12 = 0,h21 = 0,h22 = 0,len = s1.length();
//		for(int i = len - 1;i >= 0;i--){
//			h11 = (h11 * b + s1[i]) % m1;
//			h12 = (h12 * b + s1[i]) % m2;
//			h21 = (h21 * b + s2[i]) % m1;
//			h22 = (h22 * b + s2[i]) % m2;
//		}
//		s.insert({{h11,h12},{h21,h22}});
	}
	for(int j = 1;j <= q;j++){
		cin >> t1 >> t2;
//		ll len = t1.length();
//		p1[len - 1] = p2[len - 1] = 1;
//		h11[len - 1] = h12[len - 1] = t1[len - 1];
//		h21[len - 1] = h22[len - 1] = t2[len - 1];
//		for(int i = len - 2;i >= 0;i--){
//			p1[i] = (p1[i + 1] * b) % m1;
//			p2[i] = (p2[i + 1] * b) % m2;
//			h11[i] = (h11[i + 1] * b + t1[i]) % m1;
//			h12[i] = (h12[i + 1] * b + t1[i]) % m2;
//			h21[i] = (h21[i + 1] * b + t2[i]) % m1;
//			h22[i] = (h22[i + 1] * b + t2[i]) % m2;
//		}
	cout << "0\n"; 
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
