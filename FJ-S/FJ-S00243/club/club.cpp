#include <bits/stdc++.h>
using namespace std;
int t,n,sj[100001],a,b,c,a2,b2,c2,a1,b1,c1;
bool AB(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cin>>a>>b>>c;
		cin>>a1>>b1>>c1;
		if(a>a1){
			a2=a;
		}else{
			a2=a1;
		}
		if(b>b1){
			b2=b;
		}else{
			b2=b1;
		}
		if(c>c1){
			c2=c;
		}else{
			c2=c1;
		}
		a=0;
		a=c2+a2+b2-min(c2,min(a2,b2));
		cout<<a<<'\n';
	}
	return 0;
}
