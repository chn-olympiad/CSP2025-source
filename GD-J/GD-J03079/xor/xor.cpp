#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long z;
	string s;
};
node a[500010];
string deal(long long n){
	string s1="";
	while(n>0){
		s1+=(n%2)+'0';
		n=n/2; 
	}
	string s2="";
	for(int i=s1.size()-1;i>=0;i--){
		s2+=s1[i];
	}
	return s2;
}
string mix(string s1,string as){
	while(s1.size()<as.size()) s1='0'+s1;
	while(s1.size()>as.size()) as='0'+as;
//	cout<<s1<<" "<<as<<endl;
	for(int i=as.size()-1;i>=0;i--){
		if(as[i]!=s1[i]) s1[i]='1';
		else s1[i]='0';
	}
//	cout<<s1<<endl;
	return s1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	long long k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
		a[i].s=deal(a[i].z);
	}
	string xk=deal(k);
//	cout<<xk;
	int cs=0;
	string s1="";
	int index=1;
	for(int i=1;index<=n;i++){
		if(s1==""){
			s1=a[i].s;
//			cout<<s1<<"MMMMMM"<<endl;
			index=i;
			if(index>n) break;
		}else{
			s1=mix(s1,a[i].s);
		}
		if(s1==xk){
			cs++;
			s1="";
		}else if(i==n){
			i=index;
			s1="";
		}
//		cout<<s1<<endl;
	}
	cout<<cs;
	return 0;
}
