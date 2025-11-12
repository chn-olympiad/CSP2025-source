#include<bits/stdc++.h>
using namespace std;
int mian(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,x;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==w){
			 x=i;
			 break;
		}
	}
	int hang,lie;
	lie=x%m;
	hang=(x+m-1)/m;
	cout<<lie<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
