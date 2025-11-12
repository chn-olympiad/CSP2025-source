#include<bits/stdc++.h>
using namespace std;
long long n,k1;
long long a[500005];
string k;
int ans=INT_MIN;
string zh(int n){
	string s="";
	while(n!=0){
		s+=char(n%2+'0');
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string x(string s1,string s2){
	string s="";
	if(s1.size()>s2.size()){
		while(s1.size()!=s2.size()){
			s2+='0';
		}
	}else{
		while(s1.size()!=s2.size()){
			s1+='0';
		}
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]) s+='1';
		else s+='0';
	}
	return s;
}
void d(int i,int num,string last,bool z){
	if(i>=n){
		ans=max(num,ans);
		return;
	}
	string s;
	if(z) s=x(last,zh(i));
	else s=zh(i);
	if(k==s){
		d(i+1,num+1,"",0);
	}
	else{
		d(i+1,num,"",0);
		d(i+1,num,s,1);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	k=zh(k1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	d(0,0,"",0);
	cout<<ans;
	return 0;
}
