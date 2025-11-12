#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h,l,mmu=0,nk,ns;
	cin>>n>>m;
	cin>>h;
	for(int i=1;i<m*n;i++){
		cin>>l;
		if(l>h){
			mmu++;
		}
	}
	nk=mmu/n;
	ns=(mmu%n)+1;
	if(nk%2==1){
		ns=n-ns+1;
	}
	cout<<nk+1<<' '<<ns;
	return 0;
}
//94 95 96 97 98 99 100 93 92
/*3 3
94 95 96 97 98 99 100 93 92*/
//°Í°Í²©Ò»; 
