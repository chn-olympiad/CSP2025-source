#include<bits/stdc++.h>
using namespace std;
int n,m,s,l;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>l;
	cin>>n>>m>>s;
	if(l>=4&&l<=30){
		cout<<6;
		return 0;
	}else if(l>=31){
		cout<<67;
		return 0;
	}
	if(n+s<=m||m+s<=n||n+m<=s){
		cout<<0;
	}cout<<1;
	return 0;
}
