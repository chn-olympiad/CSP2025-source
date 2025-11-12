#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,cj,pm=1;
	cin>>n>>m;
	cin>>cj;
	for(int i=0;i<n*m;i++){
		cin>>a;
		if(a>cj){
			pm+=1;
		}
	}
	int lie,hang;
	if(pm%n==0){
		lie=pm/n;
		if(lie%2==1){
			hang=n;
		}else{
			hang=1;
		}
	}else{
		lie=pm/n+1;
		if(lie%2==1){
			hang=pm-(lie-1)*n;
		}else{
			hang=n-(pm-(lie-1)*n)+1;
		}
	}
	cout<<lie<<' '<<hang<<endl;
	return 0;
}
