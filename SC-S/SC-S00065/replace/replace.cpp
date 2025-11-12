#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6;
int n,q,tmp;
string s1[N],s2[N],n3,t1,t2;
void dfs(int x,string nn,string n1,string n2){
	if(x == n2.size()){
		if(nn == n2) tmp++; 
		return;
	}
	for(int i = 0;i < n2.size();i++){
		if(n1[i] == n2[i]){
			nn += n1[i];
		}else{
			dfs(x + 1,nn + s2[x],n1,n2);
			dfs(x + 1,nn,n1,n2);
		}
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int j = 0;j < q;j++){
		cin >> t1 >> t2;
		tmp = 0;
		dfs(0,n3,t1,t2);
		cout << tmp << endl;
	}
	return 0;
} 