#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	
	string s;
	cin>>s;
	long long num[s.size()]={},numi=0;
	
	for(int i=0;i<=int(s.size());i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			num[numi]=int(s[i])-48;
			numi++;
			
		}
	}
	sort(num,num+numi,cmp);
	for(int i=0;i<numi;i++){
		cout<<num[i];
	}
	return 0;
}
