#include <bits/stdc++.h>
using namespace std;
int T,n,a[500005][4],x,b[500005];
int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	cin>>T;
	while(T--){
		int maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		if(n==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					maxx=max(maxx,a[1][i]+a[2][j]);
				}
			}
		}
		else if(n>2){
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+1+n);
			int t=0;
			int i=n;
			while(t<=n/2){
				t++;
				if(t>n/2) break;
				maxx+=b[i];
				i--;
			}
		}
		cout<<maxx<<endl;
	}
} 
