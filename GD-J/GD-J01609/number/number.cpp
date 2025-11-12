#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n[20]={0};
	char str[20]={'0','1','2','3','4','5','6','7','8','9'};
	for(int i=0;i<s.size();i++){
		int x=s[i];
		for(int j=0;j<10;j++){
			if(x==str[j])n[j]++;
		}
	}
	int ans=0;
	for(int i=1;i<10;i++)ans+=n[i];
	if(ans==0){
		cout << 0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(n[i]){
			cout << i;
			n[i]--;
		}
	}
	return 0;
}
