#include<iostream>
#include<vector>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	int s;
	vector<int> a;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	for(int i=0;i<n*m-1;i++){
		for(int j=i+1;j<n*m;j++){
			int d=a[i];
			if(a[j]>a[i]){
				s=a[j];
				a[j]=a[i];
				a[i]=s;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			cout<<k;
			int b=i+1;
			if(b%n==0) c=b/n;
			else c=b/n+1;
			if(c%2!=0) r=b%n;
			else r=n-b%n+1;
		}
	}
	cout<<c<<r;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}