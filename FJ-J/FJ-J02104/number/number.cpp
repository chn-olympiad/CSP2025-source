#include<bits/stdc++.h>
using namespace std;
string s;
int a[101010];
int tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}

	for(int i=0;i<=9;i++){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
