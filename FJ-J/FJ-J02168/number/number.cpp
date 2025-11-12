#include<bits/stdc++.h>

using namespace std;

int a[12];
long long ans=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'1'+1]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		while(a[i]--){
		//	ans*=10;
		//	ans+=i;
		cout<<i;
		}
	}
	
//	cout<<ans;
	
	return 0;
}
