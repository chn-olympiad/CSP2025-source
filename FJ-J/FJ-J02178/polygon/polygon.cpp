#include<bits/stdc++.h>
using namespace std;
int n,CCF[10000],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>CCF[i];
		sum+=CCF[i];	
	}
	sort(CCF+1,CCF+n+1,cmp);
	if(sum>2/CCF[1]){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
