#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cnd(char a,char b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char c[N];
	long long a=1;
	string b="";
	long long ans;
	long long l=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[l]=s[i];
			l++;
		}
	}
	sort(c,c+l,cnd);
	for(long long i=l-1;i>=0;i--){
		ans=ans+int(c[i]-'0')*a;
		a=a*10;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
