#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=s.length(),al=0;
	for(int i=0;i<sl;i++){
		if(isdigit(s[i])){
			int k=s[i]-'0';
			a[k]++;
		}
	}
	string ans;
	for(int i=9;i>=0;i--){
		while(a[i]){
			ans+='0'+i;
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
} 
