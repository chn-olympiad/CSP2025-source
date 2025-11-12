#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
			n++;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=9;i>=0;i--){
			if(a[i]!=0){
				cout<<i;
				a[i]--;
				break;
			}
		}
	}
	
} 
