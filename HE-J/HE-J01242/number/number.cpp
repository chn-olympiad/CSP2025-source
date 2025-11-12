#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1;
ll a[1000001];
string ans="";
ll top=0;
char c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.length();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			a[++top]=s1[i]-'0';
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		c=a[i]+'0';
		ans+=c; 
	}
	cout<<ans;



	return 0;
	fclose(stdin);
	fclose(stdout);
}

