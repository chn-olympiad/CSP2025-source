#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s;
int n=0,a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<'\n';
	return 0;
}
/*
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout); 
froepen("number.in","r",stdin);
freopen("number.out","w",stdout)
freopen("number.in","w",stdin);
freopen("number.out","w",stdout)
freopen("number.in","r",stdin);
freopen("number.out","a+",stdout)
freopen("number.in","r",stdin);
freopen("number.out","a+",stdout)
你好，你如果要看我的代码你会发现一堆奇奇怪怪的 freopen
好素材！ 

*/