#include<bits/stdc++.h>
using namespace std;
int n,m,r=1,c=1,a[114514],k;
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			cout<<c<<' '<<r;
			return 0;
		}
		if(f&&r==n){
			c++;
			f=0;
		}
		else if(!f&&r==1){
			c++;
			f=1;
		}
		else if(f&&r!=n){
			r++;
		}
		else if(!f&&r!=1){
			r--;
		}
	}
	return 0;
}//ATLETICO MADRID
