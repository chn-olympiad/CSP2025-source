#include <bits/stdc++.h>
using namespace std;
int n,m,k,x=1,y=1,s=1;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+(n*m));
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			k=i;
			break;
		}
	}
	while(k--){
		if(x!=n and s==1){
			x++;
		}else if(x==n and s==1){
			y++;
			s=0;
		}else if(x!=1 and s==0){
			x--;
		}else if(x==1 and s==0){
			y++;
			s=1;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
