#include<bits/stdc++.h>
using namespace std;
	int p,n;
	int a[100],b[100],c[100],d[100],e[100],mm,nn,bb,mii;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>p;
	int sd;
	
	for(int i=0;i<p;i++){
	   
	    cin>>n;
//	    d=n/2;
		mm,bb=0;
		for(int i=n;i>0;i--){
		
			cin>>a[i]>>b[i]>>c[i];
			
			mm=max(a[i],b[i]);
			bb=max(mm,c[i]);
		nn+=bb;
		}	cout<<nn<<endl;
//		for(int i=0;i<n;i++){
//			nn+=d[i];
//		}
		
	}
	

	return 0;
}
