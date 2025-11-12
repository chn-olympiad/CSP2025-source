#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int num[106];
	int n,m,l,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
		if(i==1) l=num[1];
		else if(num[i]>l) sum++; 
	}
	if((sum/n)%2==0){
		if(sum%n==0) cout<<sum/n<<' '<<1;
		else if(sum%n==1) cout<<sum/n+1<<' '<<1;
		else cout<<sum/n+1<<' '<<sum%n;	
	}
	else{
		if(sum%n==0) cout<<sum/n<<' '<<n;
		else if(sum%n==1) cout<<sum/n+1<<' '<<n;
		else cout<<sum/n+1<<' '<<n-sum%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}