#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[20][20],s[510],x;
int i,j,p=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(i=1;i<=n*m;i++){
		cin >> s[i];
	}
	x=s[1];
	sort(s+1,s+1+n*m,cmp);
	i=1;
	j=1;
	for(j=1;j<=m;j++){
		if( i < 1 )  i++;
		if( i > n )  i--;	
		while( i >= 1 && i <= n ){
			a[i][j] = s[p];
			if( j % 2 == 1 ) i++;
			else i--;
			p++;
		}	
	}
	for( i=1;i<=n;i++ ){
		for( j=1;j<=m;j++ ){
			if( a[i][j] == x ){
				cout << j << " " << i;
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

