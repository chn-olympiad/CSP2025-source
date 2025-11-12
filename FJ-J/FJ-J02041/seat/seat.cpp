#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	vector<int>a(n*m);
	cin>>a[0];
	int r=a[0];
	for(int i=1;i<n*m;i++)
	cin>>a[i];
	
	sort(a.begin(),a.end());
	for(int i=0;i<=n*m-1;i++){
		if(a[i]==r){
			r=n*m-i;
			break;
		}
	}
	
	if(r%n!=0){
		cout<<r/n+1<<" ";
		if((r/n+1)%2==0)
		cout<<n-r%n;
		else
		cout<<r%n;
	}
	else{
		cout<<r/n<<" ";
		if(r/n%2!=0)
		cout<<n;
		else
		cout<<1;
	}
	
	
	
	return 0;
}
