#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int k=a[1];
	for(int i=1;i<=n*m;i++){
		int flag=0;
		for(int j=1;j<=n*m-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}
	int y=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) y=i;
	} 
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<ceil((i+0.0)/n)<<" ";
		}
	}
	int ans=0;
	int h=0,l=1;
	if(y==1){
		cout<<1;
		return 0;
	}
	else{
		for(int i=1;i<=y;i++){
			if(ceil((i+0.0)/n)>l) l++;
			else if(l%2==0) h--;
			else if(l%2!=0) h++;
		}	
	}	
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
