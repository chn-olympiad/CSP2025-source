#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
char s[N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> s[i];
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	cout << m;
}
