#include<bits/stdc++.h>
using namespace std;

int d[12];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9')
			d[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<d[i];j++)cout<<i;
	}
	return 0;
}
