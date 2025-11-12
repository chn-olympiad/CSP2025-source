#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],i,j;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j++]=int(s[i]-'0');
		}
	}
	sort(a,a+j,cmp);
	for(i=0;i<j;i++){
		printf("%d",a[i]);
	}
	return 0;
}
