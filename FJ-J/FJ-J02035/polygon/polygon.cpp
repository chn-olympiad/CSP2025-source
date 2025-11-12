#include<bits/stdc++.h>
using namespace std;
int s[5555];


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(s+1,s+1+n);
	if(n==3){
		if(s[1]+s[2]>2*s[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	
	return 0;
}

