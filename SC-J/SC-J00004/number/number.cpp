#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int flag=0;
	string s;
	cin>>s;
	vector<int>a(15,0);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]>='1'&&s[i]<='9') flag=1;
			a[s[i]-'0']++;
		}
	}
	if(flag==1){
		for(int i=9;i>=0;i--){
			while(a[i]!=0){
				cout<<i;
				a[i]--;
			}
		}
	}
	else cout<<0;
}
