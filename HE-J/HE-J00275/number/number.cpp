#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=false;
int sum[20]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum[(int)s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(sum[i]>0){
			printf("%d",i);
			sum[i]--;
			flag=true;
		}
	}
	return 0;
}
