#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),idx=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[idx]=int(s[i]-'0');
			idx++;
		}
	}
	sort(a+1,a+idx,cmp);
	for(int i=1;i<idx;i++){
		cout<<a[i];
	}
	return 0;
}

