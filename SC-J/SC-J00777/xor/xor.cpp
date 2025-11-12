#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
string erjinzhi(int a){
	if(a==0){
		return "0";
	}
	string s="";
	while(a!=0){
		int h=a%2;
		a/=2;
		char c=h+48;
		s+=c;
	}
	string ans="";
	for(int i=s.length()-1;i>=0;i--){
		ans += s[i];
	}
	return ans;
}
int zhuanshi(string a){
	int sm=0;
	for(int i=a.length()-1,j=0;i>=0;i--,j++){
		sm += (a[i]-'0')*pow(2,j);
	}
	return sm;
}
string yihuo(string a,string b){
	if(a.length()!=b.length())//补0
	{
		if(a.length()<b.length()) swap(a,b);
		int len = a.length()-b.length();
		for(int i=1;i<=len;i++){
			b = '0'+b;
		}
	 } 
	string jieguo = "";
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]) jieguo+="1";
		else jieguo+="0";
	}
	return jieguo;
}
long long arr[N];
long long sm;
string ans;
long long n,k;
void dfs(int now,string now_jieguo){
	if(k == zhuanshi(now_jieguo)){
		sm++;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,yihuo(now_jieguo,erjinzhi(i)));
	}
}
int main(){
	//写freopen(注意空格！！！),提交记得注释，换行用"\n"!!! fc来对比！记得对拍! 
	freopen("xor.in", "r",stdin);
	freopen("xor.out", "w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,erjinzhi(i));
	}
	cout<<sm;
	return 0;
} 