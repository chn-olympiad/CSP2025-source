#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,s[105][105],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		scanf("%d",&a[i]);
	} 
	r=a[1];
	for(int i=1;i<=m*n;i++){
		int h;
		for(int j=i;j<=m*n;j++){
			if(a[j]>a[i]){
				h=a[i];
				a[i]=a[j];
				a[j]=h;
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(r==a[i]){
		    p=i;
		    break;
	    }
	}
	int l;
	if(p%n==0){
		cout<<p/n<<' ';
		l=p/n;
		if(l%2==0){
			int c=p-n*(l-1);
			cout<<n-c+1;
		}
		else{
			cout<<p-n*(l-1);
		}
	}
	else{
		cout<<p/n+1<<' ';
		l=p/n+1;
			if(l%2==0){
			int c=p-n*(l-1);
			cout<<n-c+1;
		}
		else{
			cout<<p-n*(l-1);
		}
	}
	return 0;
}
