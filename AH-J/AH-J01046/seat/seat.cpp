#include<bits/stdc++.h>
using namespace std;
long long n,m,s[30][30],sc,t[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t[i];
	}
	sc=t[1];
	sort(t+1,t+n*m+1,greater<int>());
	int a=1,b=1;
	for(int i=1;i<=n*m;i++){
		s[a][b]=t[i];
		if(b%2==1){
			if(a==n){
				b++;
			}else{
				a++;
			}
		}else{
			if(a==1){
				b++;
			}else{
				a--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==sc){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}	
}
