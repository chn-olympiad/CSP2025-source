#include<bits/stdc++.h>
using namespace std;
string s;
int a[1010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	cin>>s;
	int n=s.size();
	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
