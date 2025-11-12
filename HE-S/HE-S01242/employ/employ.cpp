#include<bits/stdc++.h>
using namespace std;
const int N= 510;
int a[N];
int main (){
	freopen("employ.in","r",stdin);
	freopen("emply.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	char c;
	cin >> c;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	return 0;
}
