#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char c[1000005];
	cin>>s;
	long long l=s.size(),num=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			c[i]=s[i];
		}
	}
	sort(c,c+l,cmp);
	for(int i=0;i<num;i++){
		cout<<c[i];
	}
	return 0;
}
