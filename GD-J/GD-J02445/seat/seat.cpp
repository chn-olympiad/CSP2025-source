#include<bits/stdc++.h>
using namespace std; 
int myfind(vector<int> v , int x){
	for(int i = 0 ; i < v.size() ; i++) if(v[i] == x) return i;
	return -1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,finda1;
	cin >> n >> m;
	vector<int> v(n*m);
	for(int i = 0 ; i < n*m ; i++) cin >> v[i];
	finda1 = v[0];
	sort(v.begin(),v.end(),greater<int>());
	int found = myfind(v,finda1);
	if((found / m) % 2) cout << (found/m)+1 << ' ' << m-(found%m);
	else cout << (found/m)+1 << ' ' << (found%m)+1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
