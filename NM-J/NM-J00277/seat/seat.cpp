#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,r,d=0;
	int a[103];
	bool f=false;
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	for(int i=1;i<n*m;i++){
		if(a[i]>a[i-1]){
			d=a[i-1];
			a[i-1]=a[i];
			a[i]=d;
			for(int j=i;j>=1;j--){
				if(a[j]>a[j-1]){
					d=a[j-1];
			a[j-1]=a[j];
			a[j]=d;
				}
			}
		} 
	}
	int cnt=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt+=1;
			if(a[cnt]==r) {
				cout<<i<<" "<<j<<endl;
				f=true;
				break;
			}
		}
		if(f) break;
	}
	return 0;
}

