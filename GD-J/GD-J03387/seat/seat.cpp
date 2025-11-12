#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int  a;
	cin>>a;
	int sum=0,num=n*m;
	int ls;
	for(int i=1;i<n*m;i++){
		cin>>ls;
		if(ls>a) sum++;
	}
	sum++;
	int ans=sum/n;
	sum%=n;
	if(sum==0){
		cout<<ans<<" ";
		if(ans & 1) cout<<n;
		else cout<<1;
	}
	else {
		cout<<ans+1<<" ";
		if((ans+1) & 1) cout<<sum;
		else cout<<n-sum+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
