#include<bits/stdc++.h>
using namespace std;
const int N=1e5+101;
int n,m,a[N],maxn=-1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(maxn<a[i]){
			maxn=a[i];
		}
	}
	cout << maxn;
	return 0;
} 
