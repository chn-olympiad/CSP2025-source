#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	bool flag=0;
	for(int i=9;i>=0;i--){
		if(t[i]>0&&i!=0){
			flag=1;
			for(int j=1;j<=t[i];j++) cout<<i;
		}else if(i==0){
			if(!flag) cout<<0;
			else for(int j=1;j<=t[i];j++) cout<<i;
		}	
	}
	return 0;
}
