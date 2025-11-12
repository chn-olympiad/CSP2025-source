#include<bits/stdc++.h>
using namespace std;
int n,k,m,s[1005],h,l,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	for(int i=1;i<=n*m;i++){
		if(s[i]>=k) x++;
	}
	l=(x-1)/m+1;
	if(l%2==0){
		h=m-(x%m)+1;
		if(h==m+1) h=1;
	}
	else{
		h=x%m;
		if(h==0) h=m;
	} 
	cout<<l<<' '<<h;
	return 0;
}

