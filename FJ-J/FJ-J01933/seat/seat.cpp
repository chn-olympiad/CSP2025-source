#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],a1,c;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	a[n*m]=0;
	sort(a+1,a+n*m,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]<=a1 && a[i-1]>a1){
			c=i;
			break;
		}
	}
	if(((c-1)/n+1)%2==0){
			cout<<(c-1)/n+1<<' '<<n-(c-1)%n;
	}else{
			cout<<(c-1)/n+1<<' '<<(c-1)%n+1;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
