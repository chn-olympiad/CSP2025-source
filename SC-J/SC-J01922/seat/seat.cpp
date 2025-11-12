#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int tt;
	scanf("%d",&tt);
	int ans=0;
	for(int i=1,t;i<n*m;i++){
		scanf("%d",&t);
		if(tt<t)ans++;
	}
	ans++;
	int lie=(ans+n-1)/n,hang;
	if(lie%2==0){
		hang=n+1-ans%n;
	}else{
		hang=ans%n;
		if(hang==0){
			hang=n;
		}
	}
	cout<<lie<<' '<<hang;
	return 0;
} 