#include<bits/stdc++.h>
using namespace std;
int n,m,nx[505],s,x[505];
string ha;
struct peo{
	int olid;
	int neid;
	int nx;
}people[505];
bool so(peo x,peo y){
	return x.nx>y.nx;
}
int main(){
	freopen("emploty.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d%d%s",&n,&m,&ha);
	for(int i=1;i<=n;i++){
		scanf("%d",&people[i].nx);
		people[i].olid=i;
		people[i].neid=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			else{
				
			}
		}
	}
	return 0;
}





