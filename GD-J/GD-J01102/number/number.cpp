#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans,ansss;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long anss=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			if(s[i]=='0'){
				ansss++;
			}
		}
		else{
			s[i]='0';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
				a[i]=s[i]-'0';
			anss++;
		}
	}
	sort(a,a+anss+1,cmp);
	for(int i=0;i<anss;i++){
		if(a[i]>=1)
		cout<<a[i];
	}
	for(int i=1;i<=ansss;i++){
		cout<<"0";
	}
	return 0;
}
