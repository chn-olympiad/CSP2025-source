#include<bits/stdc++.h> 
using namespace std;
int n,m;
int c,r=1;
int s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n*m+5);
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	r=1;
	sort(a.begin()+1,a.end(),greater<int>());
	for(int j=1;j<=n;j++){
	for(int i=1;i<=m;i++){
		s[i][j]=a[r];
		r++;
		if(s[i][j]==c){
			if(j%2==0){
				cout<<j<<" "<<n+1-i;
			}
			else if(j%2==1){
				cout<<j<<" "<<i;
			}
		}
	}}
	return 0;
}
