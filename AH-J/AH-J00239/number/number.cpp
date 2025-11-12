#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],x;
bool cmp(int xx,int yy){
	return xx>=yy;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=1;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a+1,a+x,cmp);
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
