#include<bits/stdc++.h>
using namespace std;
int a[114514],a1,xy;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			xy=i;
			break;
		}
	}
	if(xy%n==0){
		cout<<xy/n;
		if(xy/n%2!=0){
			cout<<" "<<n;
			return 0;
		}else{
			cout<<" "<<1;
			return 0;
		}
	}else{
		cout<<xy/n+1;
		int u=xy-(xy/n)*n;
		if((xy/n+1)%2==0){
			cout<<" "<<n-u+1;
		}else{
			cout<<" "<<u;
		}
	}
	
	return 0;
} 
