#include<bits/stdc++.h>
using namespace std;
int k[1000005];
bool cmp(int a,int b){
	return a>b;
	
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=1;
	string s;
	cin>>s;
	for(long unsigned int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k[a]=s[i]-'0';
			a++;
		}
	}
	sort(k+1,k+1+s.size(),cmp);
	for(int i=1;i<a;i++){
		cout<<k[i];
	}
	
	return 0;
}
