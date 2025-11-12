#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,num,k,san=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	num=k;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&k);
		if(k>num)san+=1;
	}
	san+=1;
	if(san<n){
		cout<<1<<" "<<san;
		return 0;
	}
	if(san%n==0&&san>=n){
		if((san/n)%2!=0)cout<<(san/n)<<" "<<n;
		else cout<<(san/n)<<" "<<1;
		return 0;
	}
	if((san/n)%2!=0)cout<<san/n+1<<" "<<n-(san-(san/n)*n)+1;
	else cout<<san/n+1<<" "<<san-(san/n)*n;
	return 0;
}
