#include<bits/stdc++.h>
using namespace std;
long long px[105],findd,ccf;
double s,n,m;
int finddd(int i){
	if(px[i]==findd){
		return i;
	}
	return finddd(i+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>px[0];
	findd=px[0];
	for(int i=1;i<n*m;i++){
		cin>>px[i];
	}
	sort(px,px+int(m*n));
	s=m*n-finddd(0);
	ccf=ceil(s*1.0/m);
	if(ccf%2==1){
    	cout<<ccf<<' '<<s-((ccf-1)*n);
	}
	else{
		cout<<ccf<<' '<<n+1-(s-(ccf-1)*n);
	}
	return 0;
} 