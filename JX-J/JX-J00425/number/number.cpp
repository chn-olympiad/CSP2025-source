#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],i1=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i1]=int(s[i])-'0';
			i1++;
		}
	}
	sort(a+1,a+1+i1,greater<int>());
	for(int i=1;i<i1;i++){
		cout<<a[i];
	}
	return 0;
}
