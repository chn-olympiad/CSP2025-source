#include <bits/stdc++.h>
using namespace std;
int a[105],m,n;
void px(){
	int k=1;
	bool flag=1;
	while(1){
		flag=1;
		for(int i=k+1;i<m*n;i++){
			if(a[k]<a[i]){
				swap(a[k],a[i]);
				flag=0;
			}
		}
		k++;
		if(flag==1) return;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	px();
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	int w;
	if(k%n!=0) w=k/n+1;
	else w=k/n;
	cout<<w<<' ';
	k-=(w-1)*n;
	if(w%2==0){
		cout<<m-1+k;
	}
	else {
		cout<<k;
	}
	return 0;
}
