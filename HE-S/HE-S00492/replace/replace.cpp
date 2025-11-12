#include<bits/stdc++.h>
using namespace std;
long long n,m,l,ans;
string p1,p2;
int const N = 1e6 + 5;
string a[N][2];
void th(string p1,string p2,int l){
	for(int i = 0;i < n;i++){
		long long l1 = a[i][0].size();
		for(int i = 0;i < l - l1 + 1;i++){
			string strs;
			for(int j = i;j < l1;j++){
				strs += p1[j];
			}
			if(strs == a[i][0]){
				for(int j = i;j < l1;j++){
					p1[i] = a[i][1][j - i];
				}
			}
			if(p1 == p2){
				ans++;
			}
			else{
				l = p1.size();
				th(p1,p2,l);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i][0] >> a[i][1];
	}
	for(int i = 0;i < m;i++){
		cin >> p1 >> p2;
		l = p1.size();
		th(p1,p2,l);
		cout << ans;
	}
}
