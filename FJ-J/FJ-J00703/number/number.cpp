#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005]={0},n=0;
bool cmp(int z,int x){
	return z>x; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
} 
