#include <bits/stdc++.h>
using namespace std;
int n,a[100010],s[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(s+1,s+4);
	if(n==3){
		if(s[1]+s[2]>s[3]){
			cout<<1;
		}
		
	}

		
	
	
	
	return 0;
}
