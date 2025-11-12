#include<bits/stdc++.h>
using namespace std;

int nu[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int le=s.length(),n=0;
	for(int i=0;i<le;i++){
		if(s[i]>='0' && s[i]<='9'){
			nu[n++]=s[i]-'0';
		}
	}
	sort(nu,nu+n,cmp);
	for(int i=0;i<n;i++)
		printf("%d",nu[i]);
}
