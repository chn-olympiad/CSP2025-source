#include<bits/stdc++.h> 
using namespace std;
int b,c,d,e,f;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int n;
	cin>>n;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=n;j++){
		cin>>b>>c>>d;
		e=max(b,max(c,d));
		f=f+e;
		cout<<f;
	}
	f=0;
}
	return 0;
}
