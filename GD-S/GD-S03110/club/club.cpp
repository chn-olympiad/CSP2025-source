#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int MAXMa=1e5+10 ;
int a ;
int s;
int d;
int qwe[100500][100500];
int	p[100500];
int ans;
int sum[100500];
int main(){	
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
		cin>>a;
		for(int i=0;i<a;i++){
			cin>>s; 
			for(int j= 1;j<=s;j++){
				for(int k=0;k<3;k++){
					cin>> qwe[j][k];
			}
			for(int j=0;j<s;j++){
				p[j]=qwe[j][1];
			}
			p.sort(p+0,p+s);
			for(int j=s;j=s/2;j--}
				ans+=p[j];
			}
			cout<<ans;
		}
		return 0;
	}
