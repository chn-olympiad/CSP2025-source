#include <bits/stdc++.h> 
using namespace std;
long long c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;cin >> n >> m;
	string s;cin >> s;
	for(long long i = 1 ; i <= n ; i++){
		cin >> c[i];
	} 
	long long cur=0,cnt=0;
	while(true){
		++cur;
		bool f=1;
		for(long long i = 1 ; i <= n ; i++){
			if(cur<=c[i]){
				cnt++;
				f=0;	
			}
		}	
		if(f) break;
	} 
	cout << cnt;
	
	return 0;
}
