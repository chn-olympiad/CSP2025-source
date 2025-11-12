#include<bits/stdc++.h>
using namespace std;
int a[1000370],i;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int idx=0,num=0;
	for(i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[idx]=(s[i]-'0');
			idx++;
		}
	}
	sort(a,a+idx,cmp);
	for(i=0;i<idx;i++){
		cout<<a[i];
	}
	return 0;
}
