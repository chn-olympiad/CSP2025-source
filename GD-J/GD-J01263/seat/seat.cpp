#include<bits/stdc++.h>
using namespace std;
//记得把代码保存到D！！！ 
struct molin{
	int scmolin,idmolin;
};
molin a[100000];
int n,m; 
bool cmp(molin x,molin y){
	return x.scmolin>y.scmolin;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].scmolin;
		a[i].idmolin=i;
	} 
	sort(a+1,a+1+n*m,cmp);
	int molinrl=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].idmolin==1){
			molinrl=i;
			break;
		} 
	}
	int molincm=0,molinlm=0;
	molincm=molinrl/n;
	if(molinrl%n!=0){
		molincm++;
	}
	if(molincm%2==0){
		if(molinrl%n==0)molinlm=1;
		else molinlm=n-molinrl%n+1;
	}else{
		if(molinrl%n==0)molinlm=n;
		else molinlm=molinrl%n;	
	} 
	cout<<molincm<<' '<<molinlm;
	return 0;
} 
