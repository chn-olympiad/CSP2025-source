#include<bits/stdc++.h>
using namespace std;	
priority_queue<int>q;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long x=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
	}
	sort(a+1,a+x,cmp);
	}
	for(int i=1;i<=x-1;i++){
		cout<<a[i];
	}
	return 0;
}
