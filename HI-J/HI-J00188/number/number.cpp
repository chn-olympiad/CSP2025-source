#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
string x,ans,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for (int i=0;i<x.size();i++){
		if (x[i]>='0'&&x[i]<='9') ans+=x[i];
	}
	int y=ans.size();
	for (int i=0;i<y;i++){
		a[i]=ans[i]-'0';
	}
	sort(a,a+y);
	int zero=0;
	for (int i=y-1;i>=0;i--){
		if (a[i]>0){
			zero=1;
			cout<<a[i];
		} else{
			if (zero) cout<<0;
		}
	}
	if (zero==0) cout<<0;
	return 0; 
}
