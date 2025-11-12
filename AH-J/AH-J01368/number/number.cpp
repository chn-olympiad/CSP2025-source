#include<bits/stdc++.h>
using namespace std;
string s;
int t,a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<=ss-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<=t-1;i++){
		cout<<a[i];
	}
	return 0;
}
