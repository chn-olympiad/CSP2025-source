#include<bits/stdc++.h>
using namespace std;
string ten2two(int x){
	string ret="";
	if(x==0)return "0";
	while(x){
		if(x%2){
			ret+='1';
			x--;
		}
		else {
			ret+='0';
			x/=2;
		}
	}
	return ret;
}
int two2ten(string s){
	int ret=0,z=1;
	for(int i=0;i<s.size();i++){
		ret+=(s[i]-'0')*z;
		//cout<<z<<endl;
		z*=2;
	}
	
	return ret;
}
int n,k,a[500005],cnt;
int qj(int x,int y){
	int sum=a[x];
	for(int i=x+1;i<=y;i++){
		string s1=ten2two(sum);
		string s2=ten2two(a[i]);
		string s="";
		int x=max(s1.size(),s2.size()),y=min(s1.size(),s2.size());
		if(s1.size()>s2.size()){
			for(int j=y;j<x;j++){
				s2+='0';
			}
		}
		if(s2.size()>s1.size()){
			for(int j=y;j<x;j++){
				s1+='0';
			}
		}
		for(int j=0;j<x;j++){
			if(s1[j]!=s2[j])s+='1';
			else s+='0';
		}
		//cout<<two2ten(s)<<" "<<s1<<" "<<s2<<endl;
		sum=two2ten(s);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i){
				if(a[i]==k) cnt++;
				continue;
			}
			if(qj(i,j)==k)cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
