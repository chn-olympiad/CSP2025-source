#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[N];
	int cnt=0;
	for(int i=0;i<n;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		cout<<0;
	}else{
		for(int j=1;j<=cnt;j++)cout<<a[j];
	}
	return 0;
}
