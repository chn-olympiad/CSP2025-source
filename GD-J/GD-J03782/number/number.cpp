#include<bits/stdc++.h>
using namespace std;
int w,n,a[1000005],sum;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,-1,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+1000005,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
