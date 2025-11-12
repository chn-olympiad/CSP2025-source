#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100010]={},cnt=0;
//1 2 3 4 5-> 5 4 3 2 1
void qs(long long q[],long long l,long long r){
	if(l>=r) return;
	long long i=l-1,j=r+1,x=q[l];
	while(i<j){
		do i++;while(q[i]>x);
		do j--;while(q[j]<x);
		if(i<j) swap(q[i],q[j]);
	}
	qs(q,l,j);
	qs(q,j+1,r);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long t=s.length();
	for(long long i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-48;
		}
	}
	qs(a,0,cnt-1);
	for(long long i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
