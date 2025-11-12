#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q;
cin>>n>>q;
int c=0;
int d=0;
string s1;string s2;string s3;string s4;
while(n>0){
	getline(cin,s1);
	getline(cin,s2);
	n--;
	}
while(q>0){
	getline(cin,s3);
	getline(cin,s4);
	if(s4==s1||s4==s2){
		c++;
		}
	q--;
	}
	cout<<c<<" "<<d;
return 0;
}
