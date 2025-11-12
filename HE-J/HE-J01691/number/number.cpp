#include <bits/stdc++.h>
using namespace std;
string s1;
int a[11],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s1;
	while(s1[cnt]!=0){
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		if('0'<=s1[i]&&s1[i]<='9'){
			a[s1[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}

	return 0;
}
