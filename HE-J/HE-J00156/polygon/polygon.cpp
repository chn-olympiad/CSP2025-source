#include<bits/stdc++.h>
using namespace std;
int n=0,x=0,s=0,m=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		s=x;
		if(i+1>s){
			s=i+1;
			m+=i;
		}
		else if(m>2*s){
			cout<<m;
		}
	}
	return 0;
}
