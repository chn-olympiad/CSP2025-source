#include<bits/stdc++.h>
using namespace std;
int l[1000005],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[++n]=s[i]-48;
		}		 
	}
	sort(l+1,l+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<l[i];
	}
	return 0;
} 
