#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[10001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]){
			cout<<"1"; 
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	if(n==4){
		int d=a[1]+a[2]+a[3]+a[4],f=0;
		for(int i=1;i<=n;i++){
			f=0;
			d-=a[i]; 
			for(int j=1;j<=n;j++){
				if(d-a[j]<=a[j]){
					f=1;
					break;
				}
			}
			if(f==0){
				sum++;
			}
			if(d-a[i]<=a[i]){
				break;
			}
			if(f==0){
				sum++;
			}
			
		}
		
	}
	cout<<sum;
	return 0;
}
