#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int a[l+1]={0},num=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+l,cmp);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	return 0;
}
