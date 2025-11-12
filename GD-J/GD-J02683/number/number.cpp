#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	long long f[15]={0};
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
		}else{
			continue;
		}
	}
	bool flag=0;
	for(int i=9;i>=0;i--){
		if(f[i]!=0&&i!=0){
			//cout<<i<<" ";
			flag=1;
			for(int j=1;j<=f[i];j++){
				cout<<i;
			}
		}
		
	}
	if(flag==1){
		for(int j=1;j<=f[0];j++){
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
