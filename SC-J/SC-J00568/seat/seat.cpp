#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,b[405],l;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)	cin>>b[i];
	int x=b[1];
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(b[i]==x)	l=i;
	}if(l%n!=0){
		if((l/n)%2==0)	cout<<l/n+1<<" "<<l%n;
		else	cout<<l/n+1<<" "<<n-l%n+1;
	}else{
		if((l/n)%2==0)	cout<<l/n<<" "<<"1";
		else	cout<<l/n<<" "<<n;
	}
	return 0;
}