#include <bits/stdc++.h>
using namespace std;
string s,ss="";
int a[9];
void solve(){
	cin>>s;
	int m=s.size();
	for(int i=0;i<=m;i++){
		if('0'<=s[i]&&s[i]<='9'){
			int n=s[i]-'0';
			//cout<<n<<"\n";
			a[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			//cout<<i<<"\n";
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
