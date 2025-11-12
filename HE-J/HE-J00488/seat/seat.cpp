#include<bits/stdc++.h>
using namespace std;
int s[105],a[12][12],n,m,b,c;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout); 
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++) cin>>s[i];
	b=s[1];
	sort(s,s+c);
	for(int i=m;i>=1;i--){
		if(i%2==1) for(int j=n;j>=1;j--){
					a[j][i]=s[j];
				}
		else for(int j=1;j<=n;j++){
				a[j][i]=s[j];
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		cout<<endl;
	}
	return 0;
}
