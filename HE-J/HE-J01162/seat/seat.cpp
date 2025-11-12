#include <bits/stdc++.h>
using namespace std;
int n,m,mc,mch,mcl;
struct stu{
	int chenji;
	int id;
};
bool pp(stu a,stu b){
	return a.chenji>b.chenji;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	stu a[10086];
	for(int i=1;i<=m*n;i++){
		cin>>a[i].chenji;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,pp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			mc=i;
		}
	}
	mcl=mc/n+1;
	if(mc%n==0){
		mcl--;
	}
	if(mcl%2!=0){
		mch=mc%n;
		if(mc%n==0)
		mch=n;
	}
		
	else{
		mch=mc%n;
		if(mc%n==0)
			mch=n;
		mch=n-mch+1;
	} 
	cout<<mcl<<" "<<mch;
	return 0;
} 
