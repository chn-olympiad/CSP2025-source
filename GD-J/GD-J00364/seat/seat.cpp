#include<bits/stdc++.h>
using namespace std;
int sconm[10053]={0};
int n,m,zs;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m;
	zs=n*m;
	for(int i=1;i<=zs;i++){
		cin>>sconm[i];
	}
	int xm=sconm[1],ans=0;
	sort(sconm+1,sconm+zs+1,cmp);
	for(int i=1;i<=zs;i++){
		if(sconm[i]==xm){
			ans=i;
			break;
		}
	}
//	cout<<ans<<"\n";
	int zf=(ans-1)/n,hang=0;
	zf+=1;
	if(zf%2==0){
		hang=n-(ans-1)%n;
	}else{
		hang=(ans-1)%n+1;
	}
	cout<<zf<<" "<<hang;
	return 0;
} 
