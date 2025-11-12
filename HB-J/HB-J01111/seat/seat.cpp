#include<bits/stdc++.h>
using namespace std;
int b[105],s[15][15];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int q=1;
	int n,m;
	cin>>n>>m;
	cin>>b[1];
	int a=b[1];
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+(n*m)+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				s[i][j]=b[q++];
				if(s[i][j]==a){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				s[i][j]=b[q++];
				if(s[i][j]==a){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
	}
	return 0;
}
