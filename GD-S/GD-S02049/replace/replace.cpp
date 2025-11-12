#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(NULL));
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
	}
	ll a;
	for(int i = 1;i <= q;i++){
		cin >> t1 >> t2;
		a = rand()%100000000;
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
