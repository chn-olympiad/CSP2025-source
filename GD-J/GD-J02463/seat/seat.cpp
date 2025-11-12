#include<bits\stdc++.h>
using namespace std;
int n,m,a[1005],awz,hhg,lle;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			awz++;
		}
	}awz+=1;
	if(awz%(n*2)==0){
		lle=awz/(n*2)*2;
		cout<<lle<<' '<<1;
		return 0;
	}lle=awz/(n*2)*2+1;
	if(awz%(n*2)>n)lle++;
	if(awz%(n*2)>n){
		hhg=n-(awz%(n*2)-n)+1;
	}else{
		if(awz%n==0)hhg=n;
		else hhg=awz%(n*2);
	}cout<<lle<<' '<<hhg;
	return 0;
} 
