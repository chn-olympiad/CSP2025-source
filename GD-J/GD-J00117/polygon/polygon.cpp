#include<bits/stdc++.h>
using namespace std;
int s[999],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,a=0;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s[i];
	}
	a=max(s[0],s[1]);
	int b=max(s[2],a);
	sum=s[0]+s[1]+s[2];
	if(sum>b*2)cout<<1;
	return 0;
}
