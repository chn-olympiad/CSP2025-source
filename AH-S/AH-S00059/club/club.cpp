#include<bits/stdc++.h>
using namespace std;
int n,m,p,t;
int ans;
int num[10010][10];
int a,b,c,d,e,f;
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>num[j][1]>>num[j][2]>>num[j][3];
		}
		if(n==2){
			a=num[1][1]+num[2][2];
			b=num[1][1]+num[2][3];
			c=num[1][2]+num[2][1];
			d=num[1][2]+num[2][3];
			e=num[1][3]+num[2][1];
			f=num[1][3]+num[2][2];
			a=max(a,b);
			c=max(c,d);
			e=max(e,f);
			a=max(a,c);
			e=max(a,e);
			cout<<e;
		}
		else{
			
			for(int j=1;j<=n;j++){
			a=max(num[j][1],num[j][2]);
			a=max(a,num[j][3]);
			e+=a;
		}
		cout<<e;
			
			
			
			}
		

	}



	
	return 0;
}
