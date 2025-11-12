#include <bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int s1[100000],l=0;
	cin>>s;
	int len_s=s.size();
	for(int i=0;i<len_s;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[l++]=s[i]-'0';
		}
	}
	sort(s1,s1+l,f);
	for(int i=0;i<l;i++){
		cout<<s1[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
