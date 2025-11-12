#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=j-i+1;
			if(num<3){
				continue;
			}
			int f=0;
			long long sum=0;
			for(int k=i;k<=j;k++){
				if(a[k]>f){
					f=a[k];
				}
				sum+=a[k];
			}
			if(sum>2*f){
				ans++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans;
}
