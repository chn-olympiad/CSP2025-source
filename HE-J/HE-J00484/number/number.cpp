#include<bits/stdc++.h>
using namespace std;
string s;
int a[30];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size()-1;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool f=0;
	for(int i=9;i>=1;i--){
		while(a[i]>0){
			a[i]--;
			cout<<i;
			f=1;
		}
	}
	if(f){
		while(a[0]>0){
			a[0]--;
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
