#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,w=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			p=a[i];
		}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[j]>a[i]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			w=i;
			break;
		}
	}
	if((w-1)%n==0||w%n==0){
		if((w-1)%n==0){
			cout<<w/n+1<<" ";
		}
		else if(w%n==0){
			cout<<w/n<<" ";
		}
		int o=w/n;
		if(o%2==1){
			cout<<n;
			return 0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	else{
		cout<<w/n+1<<" ";
		int r=w/n+1;
		if(r%2==1){
			cout<<w-n*(r-1);
		}
		else{
			cout<<n-(w-n*(r-1));
		}
	}
	return 0;
} 