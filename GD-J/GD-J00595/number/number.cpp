#include<bits/stdc++.h>
using namespace std;
string s;
bool fst;
int cnt[11];
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for(char ch:s){
		if(ch>='0'&&ch<='9'){
			cnt[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]){
			if(!fst){
				if(i==0){
					cout << 0;
					return 0;
				} 
				fst=true;
			}
			for(int j=1;j<=cnt[i];j++){
				cout << i;
			}
		}
	}
	return 0;
}
