#include <bits/stdc++.h>
#define ll long long
using namespace std;
int num[105];
int sor[105];
int n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
		sor[i]=num[i];
	}
	sort(sor+1,sor+n*m+1);
	reverse(sor+1,sor+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(sor[i]==num[1]){
			k=i;
			break;
		} 
	}
	if(k%n==0){
		int t=k/n;
		if(t&1){
			cout<<t<<" "<<n<<endl;
		}
		else{
			cout<<t<<" "<<1<<endl;
		}
	}
	else{
		int t=k/n+1;
		if(t&1){
			cout<<t<<" "<<(k%n)<<endl;
		}
		else{
			cout<<t<<" "<<n-(k%n)+1<<endl;
		}
	}
	return 0;
} 