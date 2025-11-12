#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++){
			scanf("%d",&a[i]);
	}
	c=a[1];
	for(int i=1; i<n*m; i++){
		for(int j=i+1; j<=n*m; j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				if(i==w)w=j;
				else if(j==w)w=i;
			}
		}
	}
	cout<<(w-1)/m+1<<" ";
	if(((w-1)/m+1)%2==1)cout<<(w-1)%m+1;
	else cout<<n-(w-1)%m;
	return 0;
}
