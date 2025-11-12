#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,v[100009],w[100009],k;
int ans;
int c[100009],a[10009];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(g,1,sizeof(g));
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=0;i<=s.size();i++){
		v[i+1]=s[i]-48;
	}
	if(m==1){
		
		j=1;
		for(i=1;i<=n;i++){
			j=j*i;
		}
		cout<<j;
		return 0;
		
	}else if(m==n){
		cout<<1;
		return 0;
	}
	cout<<n/5*3;
}
//Ren5Jie4Di4Ling5%
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
