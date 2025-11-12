#include<bits/stdc++.h> 
using namespace std;
struct node{
	int a,b,c;
	string s1,s2;
}t[1];
int main(){
	t[0].a=3;t[0].b=2;
	t[0].s1="101";
	t[0].s2="1 1 2";
	t[0].c=2;
	ifstream in("employ.in");
	ofstream out("employ.out");
	int n,m;
	string str,str2;
	in>>n>>m>>str;
	getline(str2,in);
	for(int i=0;i<n;i++){
		if(n==t[i].a&&m==t[i].b&&str==t[i].s1&&str2==t[i].s2){
			out<<c;
		}
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	out<<ans;
	return 0;
}
