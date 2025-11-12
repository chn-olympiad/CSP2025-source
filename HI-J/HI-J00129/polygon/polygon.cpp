#include <bits/stdc++.h>
using namespace std;

int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	long long n,maxn=-1,num=0;
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	else if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			num+=a[i];
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		maxn=maxn*2;
		if(num>maxn){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
			maxn=maxn*2;
		}
	}
	double sum=0;
	if(maxn==2) {
		for(int i=3;i<=n;i++){
			double x=1;
			for(int j=1;j<=i;j++){
				x*=n-j+1;
				x=x/j;
			}
			sum+=x;
		}
		cout<<sum;
	}
	
	return 0;
}
