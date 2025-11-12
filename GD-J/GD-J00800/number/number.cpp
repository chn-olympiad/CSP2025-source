#include<bits/stdc++.h>
using namespace std;
char a;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	while(cin>>a){
		if(a>='0'&&a<='9'){
			int x=a-'0';
			cnt[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
