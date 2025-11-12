#include<bits/stdc++.h>
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
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[i]=s[i]-48;
			cnt++;
		}
	}
	int le=s.size();
	sort(a,a+le+1,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}

