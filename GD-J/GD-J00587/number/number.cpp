#include<bits/stdc++.h> 
using namespace std;
string s;
int num[100],num0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num0==9){
			cout<<0;
			return 0;
		}
		if(num[i]==0) num0++;
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
//ÃëÀ±£¡£¡£¡
