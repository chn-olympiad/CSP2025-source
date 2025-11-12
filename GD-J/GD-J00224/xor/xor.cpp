#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=110;
ll m,n,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	if(m==0){
		cout << 1;
	}
	
	return 0;
}
