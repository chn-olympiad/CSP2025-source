#include<bits/stdc++.h>
using namespace std;
string s;
int a[105],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<char(i+'0');
		}
	}
	return 0;
}
