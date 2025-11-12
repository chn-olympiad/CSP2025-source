#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	for(int j=1;j<n*m;j++){
		for(int i=1;i<n*m;i++){
			if(a[i]<a[i+1]){
				int p=a[i];
				a[i]=a[i+1];
				a[i+1]=p;
			}
		}	
	}
	int ans;
	for(int i=1;i<n*m;i++){
		if(a[i]==b){
			ans=i;
			break;
		}
	}
	int ans1;
	ans1=ans/n;
	if(ans%n!=0){
		ans1++;
	}else{
		ans1--;
	}
	int cnt;
	if(ans1%2==0){
		cnt=n-ans%n;
	}else{
		cnt=ans%n;
	}
	cout<<ans1<<" "<<cnt+1;
	fclose(stdin);
	fclose(stdout);
}
