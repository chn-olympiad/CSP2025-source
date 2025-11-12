#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[100000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
}
