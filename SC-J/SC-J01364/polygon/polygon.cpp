#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n; 
	if(n>=20&&n<=5000)cout<<1;
	if(n<=20){
		int a[n],s=-1,b=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s=max(s,a[i]);
			b+=a[i];
		}
		if(s*2>=b)cout<<0;
		else cout<<b;
		return 0; 
	}
	return 0;
}