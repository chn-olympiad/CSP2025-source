#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000010],sz = 0;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9') a[++sz] = int(s[i] - '0');
	}
	sort(a + 1,a + sz + 1,cmp);
	for(int i = 1;i <= sz;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
