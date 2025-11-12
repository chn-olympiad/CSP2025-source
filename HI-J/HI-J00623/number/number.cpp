#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
string s;
char a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long t=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i];
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
