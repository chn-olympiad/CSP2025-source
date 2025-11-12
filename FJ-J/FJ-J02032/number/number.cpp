#include<bits/stdc++.h>
using namespace std;
string s;
int a[10]={ },f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			if(s[i]-'0'>0){
				f=1;
			}
		}
	}
	if(f==0){
		cout<<0;
	}else{
		for(int i=9;i>=0;i--){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
