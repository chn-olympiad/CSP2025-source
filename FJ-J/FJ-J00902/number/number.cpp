#include<bits/stdc++.h>
using namespace std;
string s;
string num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']+=s[i];
		}
	}
	int f=0;
	for(int i=9;i>=0;i--){
		if(num[i]!=""){
			if(f==0&&i==0){
				printf("0\n");
				return 0;
			}
			cout<<num[i];
			f++;
		}
	}
	printf("\n");
	return 0;
}

