#include<bits/stdc++.h>
using namespace std;
int n,m,ns[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>ns[i];
	}
	int rc=ns[0],wz=-1;
	sort(ns,ns+n*m);
	int cs=0;
	for(int i=n*m-1;i>=0;i--){
		if(ns[i]==rc){
			wz=cs;
		}
		cs++;
	}
	//cout<<wz<<endl;
	int rc2=floor(wz/n)+1;
	if(rc2%2==1){
		cout<<rc2<<" "<<(wz%n)+1;
	}else{
		cout<<rc2<<" "<<n-(wz%n);
	}
	
	return 0;
} 
