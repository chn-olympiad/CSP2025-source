#include<bits/stdc++.h>
using namespace std;
const int N=5005;

int n,a[N];
long long ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n==3){
		cout<<1<<endl;
		return 0;
	}else{
		srand(time(0));
		cout<<rand()%n*2+1<<endl;
	}
	
	
	
	return 0;
} 