#include<bits/stdc++.h>
using namespace std;
int k,n,m,a,b,c;
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
cin>>n;
for(int i=0;i<n;i++){
	cin>>k;
	a=0;
	b=0;
	c=0;
	for(int j=0;j<k;j++){
		cin>>a>>b>>c;
		m+=max(max(a,b),max(b,c));
	}
	cout<<m<<endl;
	m=0;
}

	return 0;
}
