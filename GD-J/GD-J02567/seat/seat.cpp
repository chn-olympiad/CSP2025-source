#include<bits/stdc++.h>
using namespace std;
int n,m,f[11000],x;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
		if(i==1) x=f[i];
	}
	sort(f+1,f+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(f[i]==x){
			x=i;
		}
	}
	cout<<(x+(n-1))/n;
	if(((x+(n-1))/n)%2==1){
		if(x%n==0) cout<<' '<<n;
		else cout<<' '<<x%n;
	}
	else{
		if(x%n==0) cout<<' '<<1;
		else cout<<' '<<n-(x%n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
