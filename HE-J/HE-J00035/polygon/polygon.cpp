#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << "0" << endl;
	}
	int sum=0;
	for(int i=0;i<=n;i++){
		if(n==3){
			if(a[1]+a[2]==a[3]){
				sum=0;
				break;
			}
			if(a[1]+a[2]>a[3]){
				sum=1;
			}else if(a[1]+a[3]>a[2]){
				sum=1;
			}else if(a[2]+a[3]>a[1]){
				sum=1;
			}
		}
	}
	if(n==3){
		cout << sum << endl;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		if(n==4){
				if(a[1]+a[2]==a[3]){
				ans=0;
				break;
			}
			if(a[1]+a[2]>a[3]){
				ans+=1;
			}else if(a[1]+a[3]>a[2]){
				ans+=1;
			}else if(a[2]+a[3]>a[1]){
				ans+=1;
			}else if(a[2]+a[3]>a[4]){
				ans+=1;
			}else if(a[4]+a[3]>a[1]){
				ans+=1;
			}else if(a[1]+a[2]>a[4]){
				ans+=1;
			}else if(a[1]+a[2]+a[3]>a[4]){
				ans+=1; 
			}else if(a[1]+a[3]+a[4]>a[2]){
				ans+=1;
			}else if(a[1]+a[2]+a[4]>a[3]){
				ans+=1;
			}
		}
	}
	if(n==4){
		cout << ans << endl;
	}
	int q=0;
	for(int i=0;i<=n;i++){
		if(n==5){
				if(a[1]+a[2]==a[3]){
				q=0;
				break;
			}
			if(a[1]+a[2]>a[3]){
				q+=1;
			}else if(a[1]+a[3]>a[2]){
				q+=1;
			}else if(a[2]+a[3]>a[1]){
				q+=1;
			}else if(a[2]+a[3]>a[4]){
				q+=1;
			}else if(a[4]+a[3]>a[1]){
				q+=1;
			}else if(a[1]+a[2]>a[4]){
				q+=1;
			}else if(a[1]+a[2]+a[3]>a[4]){
				q+=1; 
			}else if(a[1]+a[3]+a[4]>a[2]){
				q+=1;
			}else if(a[1]+a[2]+a[4]>a[3]){
				q+=1;
			}else if(a[2]+a[4]>a[5]){
				q+=1; 
			}else if(a[1]+a[2]>a[5]){
				q+=1;
			}else if(a[3]+a[4]>a[5]){
				q+=1;
			}else if(a[1]+a[2]+a[3]>a[5]){
				q+=1; 
			}else if(a[1]+a[2]+a[4]>a[5]){
				q+=1; 
			}else if(a[1]+a[3]+a[4]>a[5]){
				q+=1;
			}else if(a[2]+a[3]+a[4]>a[5]){
				q+=1;
			}else if(a[1]+a[2]+a[3]+a[4]>a[5]){
				q+=1;
			}
		}
	}
	if(n==5){
		cout << q << endl;
	}
	return 0;
}
