#include<bits/stdc++.h>
using namespace std;
int n,m,R,Rc;
struct lsc{
	int a,bh;
}lsc_sl[150];
bool cmp(lsc a,lsc b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>lsc_sl[i].a;
		lsc_sl[i].bh=i;
	}
	sort(lsc_sl+1,lsc_sl+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(lsc_sl[i].bh==1){
			Rc=i;
		}
	}
	int Rhag=Rc%n,Rlin=Rc/n;
	if(Rhag!=0)Rlin++;
	cout<<Rlin<<" ";
	if(Rlin%2==1){
		if(Rhag==0)cout<<n;
		else cout<<Rhag;
	}
	else cout<<n-Rhag+1;
	return 0;
} 
