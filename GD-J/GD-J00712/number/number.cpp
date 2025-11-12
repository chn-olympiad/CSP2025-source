#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
string s;
int num[MAXN+5];
int cnt=0;

int main(){
	//AC from 1 to 3.TLE 4.
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			num[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(num,num+cnt);
	if(num[cnt-1]==0){
		cout<<0;
	}else{
		for(int i=cnt-1;i>=0;i--){
			cout<<num[i];
		}
	}
	return 0;
}
