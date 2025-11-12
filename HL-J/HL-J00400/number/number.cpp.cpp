#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
const int N=1e7+10;
long long a[N],t=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=int(s[i]-'0');
			t++;
		}
	}
	t--;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
