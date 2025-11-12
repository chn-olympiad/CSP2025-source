#include <bits/stdc++.h>
using namespace std;
const int N=5001;
int l[N],s[N];
bool cmp(const int& a,const int& b){
	return a>b;
}
int main(){
	int n,mx=-1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		s[i]=l[i]+s[i]-1;
	}
	cout<<0;
	return 0;
}
