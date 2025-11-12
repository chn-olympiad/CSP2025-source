#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int q=a[1];
	sort(a+1,a+n*m+1,[](int x,int y){return x>y;});
	for(int i=1;i<=n*m;i++) if(q==a[i]){
		q=i;
		break;
	}
	if(q%m) cout<<q/m+1<<' ';
	else cout<<q/m<<' ';
	
	
	if((q/m)&1){
		if(q%m) cout<<n-q%m+1;
		else cout<<n;
	}
	else{
		if(q%m) cout<<q%m;
		else cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
