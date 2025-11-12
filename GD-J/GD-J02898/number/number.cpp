#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int y=s.size();
	for(int i=0;i<y;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
