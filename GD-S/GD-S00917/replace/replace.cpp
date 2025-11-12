#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n,q;
map<string,string> mp;
struct str{
	int head;
	int body;
	int tail;
};
bool operator < (str x,str y){
	return y.body<x.body;
}
str makestr(int h,int b,int t){
	str ret;
	ret.head=h;
	ret.body=b;
	ret.tail=t;
	return ret;
}
map<str,int> mp2;
int is_inc(string s,string t){
	for(int i=0;i<s.length();i++){
		bool flag=1;
		for(int j=0;j<t.length();j++){
			if(s[i+j]!=t[j]){
				flag=0;
				break;
			}
		}
		if(flag==1)return i;
	}
	return -1;
}
void work1(){
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=0;i<q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int start=-1,end;
		for(int i=0;i<t1.length();i++){
			if(t1[i]!=t2[i]){
				if(start==-1)start=i;
				end=i;
			}
		}
		string str1=t1.substr(start,end-start+1),str2=t2.substr(start,end-start+1);
	}
}
void work2(){
	for(int k=0;k<n;k++){
		int a,b;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s1.length();i++){
			if(s1[i]=='b'){
				a=i;
				break;
			}
		}
		for(int i=0;i<s2.length();i++){
			if(s2[i]=='b'){
				b=i;
				break;
			}
		}
		str x=makestr(a,b-a,s1.length()-b);
		mp2[x]++;
	}
	for(int k=0;k<q;k++){
		int a,b;
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.length();i++){
			if(t1[i]=='b'){
				a=i;
				break;
			}
		}
		for(int i=0;i<t2.length();i++){
			if(t2[i]=='b'){
				b=i;
				break;
			}
		}
		for(int i=0;i<=a;i++){
			for(int j=0;j<=t1.length()-b;j++){
				str x=makestr(i,b-a,j);
				ans+=mp2[x];
			}
		}
		cout<<ans<<endl;
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	work2();
}
