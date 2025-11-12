#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000001],couunt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[couunt]=s[i]-'0';
			couunt++;
		}
	}
	sort(num,num+couunt,cmp);
	for(long long i=0;i<couunt;i++){
		cout<<num[i];
	}
	return 0;
}

