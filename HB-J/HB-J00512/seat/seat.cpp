#include "bits/stdc++.h"
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
/*
2 2
99 100 97 98
*
100 97
99  98

2 2
98 99 100 97
* 
3 3
94 95 96 97 98 99 100 93 92
*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s[102]={ };
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
		cin>>s[i];
	int r=s[1];
	sort(s+1,s+n*m+1,cmd);
    for(int i=1;i<=m;i++){
		if(i%2==1){	for(int j=1;j<=n;j++){	if(s[(i-1)*n+j]==r){  cout<<i<<" "<<j;}}}
        else{ for(int j=n;j>=1;j--)	if(s[(i-1)*n+n-j+1]==r)  cout<<i<<" "<<j;}
	}
    
    return 0;
}
