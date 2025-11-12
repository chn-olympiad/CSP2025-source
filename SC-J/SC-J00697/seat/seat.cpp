#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],b,c=0;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	cin>>b;
	for(int i=0;i<(n*m-1);i++){
		cin>>a[i];
		if(a[i]>b)c++;
	}
	if((c+1)%n==0){
		cout<<(c+1)/n<<" ";
		if((c+1)%(2*n)==0){
			cout<<1;
		}else{
			cout<<m;
		}
	}else{
		cout<<(c+1)/n+1<<" ";
		if((c+1)/n%2==0&&(c+1)%n)cout<<(c+1)%n;
		else if((c+1)/n%2==1&&m-(c+1)%n+1) cout<<m-((c+1)%n)+1;
		else cout<<1;
	}
	return 0;
} 