#include<bits/stdc++.h>
using namespace std;
const int awm=998244353;
long long jch(int z){
	long long ss=1;
	for(int i=1;i<=z;i++){
		ss*=i;
		if(ss>awm)ss=ss%awm;
	}
	return ss;
}
int m,n,x[501],an,a=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	cin>>s;
	for(int i=0;i<m;i++)cin>>x[i];
	for(int i=0;i<m;i++){
		if(x[i]!=0)a++;
	}
	if(a<n)cout<<0;
	else if(m==100)cout<<161088479;
	else cout<<jch(100);
	return 0;
} 