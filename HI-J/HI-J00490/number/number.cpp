#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j=1;
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	j=j-1;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		printf("%d",a[i]);
	}
	return 0;
}
