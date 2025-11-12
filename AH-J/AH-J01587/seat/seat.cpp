#include<bits/stdc++.h>	
using namespace std;
int n,m,k=0,u;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int o=n*m;
	for(int i=1;i<=o;i++){
		cin>>a[i];
		u=a[1];
	}
	sort(a+1,a+o+1,cmp);
	for(int i=1;i<=o;i++){
		if(a[i]==u){
			k=i;
			break;
		}
	}
	int l;
	if(k%n==0){
		cout<<k/n<<" "<<n;
	}
	else if(k%n!=0){
		l=k/n+1;
		cout<<l<<" ";
		if(l%2==1)cout<<k%n;
		else cout<<n-k%n+1;
	}
}
