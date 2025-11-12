#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],ans,mp[15][15],t,fol,neo,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) ans=a[i];
	}
	sort(a+1,a+1+n*m);
	cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1) t=1,fol=1,neo=n+1;
		else t=n,fol=-1,neo=0;
		while(t!=neo){
			mp[i][t]=a[cnt];
			cnt--;
			if(mp[i][t]==ans){
				cout<<i<<' '<<t;
				return 0;
			}
			t+=fol;
			
		}
	}
	return 0;
}