#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int n,m,a[N],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int temp=a[1],k=n*m,l=1;
	sort(a+1,a+n*m+1);
	while(a[k]!=temp) {k--; l++;}
	
	if((l-1)/m%2==0) {
		if(l%m==0) cout<<l/n<<" "<<m;
		else cout<<l/n+1<<" "<<l%m;	
	}
	else{
		if(l%m==0) cout<<l/n<<" "<<1;
		else cout<<l/n+1<<" "<<m-l%m+1;		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}