#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100];
	int b[100]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	for(int i=1;i<=n*m;i++){
		int x=-1;
		for(int j=1;j<=n*m;j++){
			if(a[j]>=x){
				x=a[j];
			}
		}
		b[i]=x;
		for(int z=1;z<=n*m;z++){
			if(a[z]==x){
				a[z]=0;
			}
		}
	}
	int w=1;
	for(int i=1;i<=n*m;i++){
		if(b[i]==s){
			break;
		}
		else{
			w+=1;
		}
	}
	int c=1,d=1;
	if(w>m && w%2!=0 && (w/m+1)%2!=0){
		c+=w/m;
		d=w%m;
	}
	else if(w<=m){
		c=1;
		d=w;
	}
	else{
		c+=w/m;
		d+=w%m;
	}
	cout<<c<<" "<<d<<endl;
	for(int i=1;i<=n*m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
