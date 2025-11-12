#include<bits/stdc++.h>
using namespace std;
int sz[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz[s[i]-'0']++;
//			cout<<"999"<<endl;
		}
	}
	int ldpd=0,suuuu=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sz[i];j++){
			if(i!=0){
				cout<<i;
				ldpd=1;
				suuuu=1;
			}else if(ldpd==1&&i==0){
				cout<<i;
				suuuu=1;
			}
		}
	}
	if(suuuu==0){
		cout<<0;
	}
	return 0;
} 
