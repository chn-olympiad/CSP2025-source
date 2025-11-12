#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=0;
	memset(a,10,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1,j=0;i>c/2;i--,j++){
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
	}
	for(int i=0;i<c;i++) cout<<a[i];
	return 0;
}
