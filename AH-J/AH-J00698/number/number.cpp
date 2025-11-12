#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1,s2="";
	long unsigned int t=0;
	cin>>s1;
	for(long unsigned int i=0;i<s1.size();i++){
		if(isdigit(s1[i])){
			s2+=s1[i];
			a[++t]=s1[i]-'0';
		}
	}
	
	sort(a+1,a+t+1,cmp);
	if(a[1]==0){
		cout<<0<<endl;
	}else{
		for(long unsigned int i=1;i<=t;i++)cout<<a[i];
		cout<<endl;
	}
	return 0;
}
