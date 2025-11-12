#include<bits/stdc++.h>
using namespace std;
string s; 
long long num[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int j=1;
	memset(num,0,sizeof(num));
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+1,num+j+1);
	for(int i=j;i>1;i--){
		cout<<num[i];
	}
	return 0;
}
