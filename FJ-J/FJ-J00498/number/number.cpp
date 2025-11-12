#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6;
int num[MAXN];

void solve()
{
	char a;
	int n = 0; 
	while(cin >> a){
		if(a >= '0' && a <= '9'){
			num[n++] = a-'0';
		}
	}
	sort(num,num+n);
	for(int i = n-1;i>=0;i--){
		cout << num[i];
	}
}

int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	solve();
	return 0;
}

