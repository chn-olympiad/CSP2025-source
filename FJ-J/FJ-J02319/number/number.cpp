#include <bits/stdc++.h>
using namespace std;
string name;
int l,m,o[1000002],j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>name;
	l=name.size();
	for(int i=0;i<l;i++){
		if(name[i]<='9'&&name[i]>='0'){
			o[j++]=name[i]-'0';
		}else continue;
	}
	sort(o,o+l,cmp);
	for(int i=0;i<j;i++)cout<<o[i];
	return 0;
}
