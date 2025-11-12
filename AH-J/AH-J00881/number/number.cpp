#include<bits/stdc++.h>
using namespace std;
int A[1000500];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),l=s.size();
	//int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			A[i+1]=s[i]-'0';
		}
		else l--;
	}
	sort(A+1,A+1+len,cmp);
	for(int i=1;i<=l;i++){
		cout<<A[i];
	}
	return 0;
}
