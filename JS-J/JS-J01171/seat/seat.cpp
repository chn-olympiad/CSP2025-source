#include<bits/stdc++.h>
using namespace std;
int n,m;
int ansc,ansr;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ar=a[1],ci=0;//r de pai ming ,pai ming
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ar){
			ci=i;
			break;
		}
	}
	int k=(ci/(2*n))*2+1;
	int cii=ci%(2*n);
	if(cii>=1&&cii<=n){
		ansc=k;
		ansr=cii;
	}else{
		ansc=k+1;
		ansr=2*n-cii+1;
	}
	cout<<ansc<<" "<<ansr;
	return 0;
}
