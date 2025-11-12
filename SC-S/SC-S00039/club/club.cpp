#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int j=0;j<t;j++){
		int n;cin>>n;
		if(n==2){
			int a1,b1,c1,a2,b2,c2;cin>>a1>>b1>>c1>>a2>>b2>>c2;
			int a=max(a1,a2);
			int b=max(b2,b1);
			int c=max(c1,c2);
			if((a==a1 && b==b1 && a1!=a2) || (a==a1 && c==c1 && b1!=b2) || (b==b1 && c==c1 && c1!=c2)){
				int z1=max(a1,max(b1,c1)),z2=max(a2,max(b2,c2));
				cout<<z1+z2<<endl;
			}
			else cout<<a+b+c-min(a,min(b,c))<<endl;
		}
		else{
			int a,b,c,f=0,s=0,th=0;
			for(int i=0;i<n;i++){
				cin>>a>>b>>c;
				if(a>b && a>c)f+=a;
				else if(b>a && b>c)s+=b;
				else th+=c;
			}
			cout<<f+s+th<<endl;
		}
	}
	return 0;
}
