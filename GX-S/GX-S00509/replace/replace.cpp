#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	int sum=0;
	long long s[MAXN][MAXN];
	long long t[MAXN][MAXN];
	long long y[MAXN][MAXN],y_re,yt[MAXN][MAXN],yt_re;
	cin>>n>>q;
	for(  int i=0 ; i<=n ; i++ )
		for(  int g=1 ; g<=2 ; g++  )
			cin>>s[g][g];
		
	for(  int j = 0 ; j <= ( q+n ) ; j++  ){
		for(  int h = 1 ; h <= 2 ; h++ )
			cin>>t[h][h];
			
	if(  y[j][j] == s[1][1]  )
		y_re=s[2][2];
	
	
	if(  yt[j][j] == t[1][1]  ){
		yt_re=t[2][2];
		sum++;}
	}
		cout<<sum;
		
return 0;
}
