#include<bits/stdc++.h>
using namespace std;
int n,m,a[225][3];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i][1];
		a[i][2]=i;
	}
	int sum=1;
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i][1]<a[j][1]){
				if(a[i][2]==1)sum++;
				else if(a[j][2]==1)sum--;
				int t=a[i][2];
				a[i][2]=a[j][2];
				a[j][2]=t;
			}
		}
	}
	if(sum%m==0){
		cout<<sum/m<<" ";
		if((sum/m)%2==1)cout<<n;
		else cout<<1;
		return 0;
	}else{
		cout<<sum/m+1<<" ";
		if((sum/m+1)%2==1)cout<<sum%m;
		else cout<<n-(sum%m)+1;
		return 0;
	}
	return 0;
} 
