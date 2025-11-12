#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),le=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[le++]=s[i]-'0';
		}
	}
	sort(a+1,a+le+1,cmp);
	for(int i=1;i<le;i++){
		cout<<a[i];
	}
	return 0;
} 
