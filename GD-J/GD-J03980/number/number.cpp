#include<bits/stdc++.h>
using namespace std;
string s;
int d[1000005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			d[++k]=s[i]-'0';
		}
	}
	sort(d+1,d+k+1);
	for(int i=k;i>=1;i--){
		cout<<d[i];
	}
	return 0;
} 
