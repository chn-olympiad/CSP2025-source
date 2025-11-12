#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+5;
int n,k,a[N];
string s[N];

string tos(int x){
	string str="";
	while(x!=0){
		if(x%2==0) str='0'+str;
		else if(x%2!=0) str='1'+str;
		x/=2;
	}
	return str;
}

int toi(string str){
	int x=0;
	for(int i=str.size()-1;i>=0;i--){
		x+=pow(2,str.size()-1-i)*(str[i]-'0');
	}
	return x;
}

string f(string s1,string s2){
	string s3="";
	if(s1.size()>s2.size()) swap(s1,s2);
	while(s1.size()<s2.size()) s1='0'+s1;
	for(int i=0;i<s2.size();i++){
		if(s1[i]==s2[i]) s3+="0";
		else s3+="1"; 
	}
	return s3;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=tos(a[i]);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j) continue;
			string cmp=s[i];
			for(int z=i+1;z<=j;z++){
				cmp=f(cmp,s[z]);
			}
			if(toi(cmp)==k) maxn=max(maxn,j-i+1);
		}
	}
	cout<<maxn;
	return 0;
}
//4 2
//2 1 0 3 
