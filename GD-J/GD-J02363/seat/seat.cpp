#include<bits/stdc++.h>
using namespace std;
int a[200];
int ans[200];
int ppp=0;
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i],ans[i]=a[i];
	}
	sort(ans+1,ans+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(ans[i]==a[1]){
			ppp=n*m-i+1;
			break;
		}
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<ans[i]<<endl;
//	}
	int ansn,ansm;
	ansm=(ppp+n-1)/n;
	if(ansm%2==1){
		if(ppp%m==0)ansn=m;
		else ansn=ppp%m;
	}else{
		int asn;
		if(ppp%m==0)asn=m;
		else asn=ppp%m;
		ansn=m+1-asn;
	}
	cout<<ansm<<' '<<ansn;
	return 0;
}
