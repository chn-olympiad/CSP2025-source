#include<bits/stdc++.h>

using namespace std;

int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++) if(a[i]==x){pos=i;break;}
	if(pos%n==0){
		if((pos/n)%2==0) cout<<(pos/n)<<" "<<1<<"\n";
		if((pos/n)%2==1) cout<<(pos/n)<<" "<<n<<"\n";
	}else{
		if((pos/n)%2==1) cout<<((pos/n)+1)<<" "<<(n-(pos%n)+1)<<"\n";
		if((pos/n)%2==0) cout<<((pos/n)+1)<<" "<<(pos%n)<<"\n";
	}
	return 0;
}