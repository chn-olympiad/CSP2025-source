#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];int b,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i]-='0';
			a[s[i]]++;
			if (ans==0)ans+=s[i];
		}
		
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
