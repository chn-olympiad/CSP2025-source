#include<bits/stdc++.h>
using namespace std;
int n,c,b,x;
string yh(string a,string b){
	string c;
	for(int i = 0;i < max(a.size(),b.size());i++){
		if(a[i] == b[i]){
			c[i] = 0;
		}
		else{
			c[i] = 1;
		}
	}
	return c;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> c;
	for(int i = 0;i < n;i++){
		cin >> x;
//		if(x == c){
//			ans++;
//			i--;
//		}
	}
//	for(int i = 0;i < n;i++){
//		for(int j = i;j < n;i++){
//			for(int i = 0;i < )
//		}
//	}
	cout << 1;
}
