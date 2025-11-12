#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
		b[++n]=a[i]-'0';
		}
	}
	sort(b+1,b+n+1);
	if(b[n]==0){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=n;i>=1;i--) cout<<b[i];
	/*
	我注释起来应该没事 
	T1应该是没问题了 
	*/
	return 0;
}
