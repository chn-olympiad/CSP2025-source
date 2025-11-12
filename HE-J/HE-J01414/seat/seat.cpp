#include <bits/stdc++.h>
using namespace std;
int m,n;
int p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ent=n*m;
	cin>>p;
	int c=1;
	for(int i=1;i<ent;i++){
		scanf("%d",&q);
		if(q>p){
			c++;
		}
	}int l=c/n,h,cnt=c-(l*n);
	if(cnt==0){
		if(l%2==0){
			h=m-cnt+1;
		}else{
			h=m;
		}
	}else{
		l+=1;
		if(l%2==0){
			h=m-cnt+1;
		}else{
			h=cnt;
		}
	}cout<<l<<" "<<h;
	return 0;
}
