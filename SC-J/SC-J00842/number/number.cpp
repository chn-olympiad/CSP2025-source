#include<bits/stdc++.h>
using namespace std;

string s;
int len=0;

int q[1000011],idx=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) if(s[i]>='0' && s[i]<='9') q[++idx]=((int)(s[i]-'0'));
	sort(q+1,q+1+idx,cmp);
	for(int i=1;i<=idx;i++) printf("%d",q[i]);
	printf("\n");
	return 0;
}