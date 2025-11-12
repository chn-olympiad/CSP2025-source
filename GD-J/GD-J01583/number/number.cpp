#include <bits/stdc++.h>
using namespace std;
int a[1000000];
string s;
int top=1;
void aaa(int l,int r){
	int l1=l;
	int r1=r;
	int mid=(a[l]+a[r])/2;
	while(l<=r){
		while(a[l]>mid) l++;
		while(a[r]<mid) r--;
		if(l<=r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
	if(l1<r) aaa(l1,r);
	if(r1>l) aaa(l,r1);
}
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9||s[i]-'0'==0){
			a[top]=s[i]-'0';
			top++;
		}
	}
	aaa(1,top-1);
	for(int i=1;i<=top-1;i++) fout<<a[i];
	return 0;
}
