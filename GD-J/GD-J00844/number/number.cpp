#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
void solve(){
	cin >> s;
	bool f=0;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			if (x!=0){
				f=1;
			}
			a[x]++;
		}
	}
	if (f){
		for (int i=9;i>=0;i--){
			for (int j=1;j<=a[i];j++){
				cout << i;
			}
		}
	}else{
		cout << 0;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
