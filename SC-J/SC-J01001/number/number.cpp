#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a=s.length();
	int can_u[a+10];
	long long t=0;
	for(long long i=0;i<=a;i++){
		if(s[i]<='9'&&s[i]>='0'){
			can_u[t]=s[i]-'0';
			t++;
		}
	}
	sort(can_u,can_u+t,cmd);
	for(long long i=0;i<t;i++){
		cout<<can_u[i];
	}
	return 0;
}