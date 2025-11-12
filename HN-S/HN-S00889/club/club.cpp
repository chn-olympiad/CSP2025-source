#include<bits/stdc++.h>
using namespace std;
int wap(int x,int y){
	return x>y;
}
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		if(n==2){
			int a1,a2,a3,a4,a5,a6;
			cin>>a1>>a2>>a3;
			cin>>a4>>a5>>a6;
			a1=max(a1,a4);
			a2=max(a2,a5);
			a3=max(a3,a6);
			cout<<a1+a2+a3<<endl;
		}
		int mun=0,b[n+3][3];
		for(int i=1;i<=n;i++){
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			mun+=b[i][2];
		}
		cout<<mun<<endl;
	}
	return 0;
 } 
