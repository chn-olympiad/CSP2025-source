#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9' && s[i]>='0'){
			a[i]=(int)s[i]-'0';
			b++;
		}
	}
	sort(a,a+len);
	for(int i=len;i>=0;i--){
		if(a[i]!=-1)cout<<a[i];
	}
	return 0;
}
