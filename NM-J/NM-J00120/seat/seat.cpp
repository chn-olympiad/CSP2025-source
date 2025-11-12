#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int c=1,r=1,k=a[1];
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
			if(a[i]>a[j])
			swap(a[i],a[j]);
		}
	}
	for(int i=1;a[i]!=k;i++){
		if(a[i]!=k){
			if((r==n&&c%2==1)||(r==1&&c%2==0))
				c++;
			else if(r<n&&c%2==1)
				r++;
			else if(r>1&&c%2==0)
				r--;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
