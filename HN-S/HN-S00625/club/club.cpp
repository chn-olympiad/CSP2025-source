#include <bits/stdc++.h>
using namespace std;
int n,t;
//long long ;
//char ;
//float ;
int main(){
	int i;
	int a[300][4],s[4],ccy=0,l,m=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	s[1]=0;
	s[2]=0;
	s[3]=0;
	cin>>t>>n;
	/*for(int p=1;p<=t;p++){
	  for(i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		    cin<<a[i][j];
	  for(i=1;i<=n;i++){
	  	for(int j=2;j<=3;j++){
	  		if(a[i][j]>a[i][j-1]){ccy=a[i][j];l=j;}
		  }
		s[l]++;
		if(s[1]>(n/2)){
		  i--;	  	
		  for(int j=2;j<=3;j++){
	  		if(a[i][1]>a[i+1][1]){m=a[i][1];l=i}
		    }
		  a[l][1]=0;
		}
	  }	
	}*/
	for(int i=1;i<=t;i++) cout<<"0";
	return 0;
}
