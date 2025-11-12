#include<bits/stdc++.h>
using namespace std;
int t,num,num1=0,num2,num3,maxn=0,minn=0,i;
int a=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n;
	cin>>n;
	for(int j=0;j<=n;j++){
		for(int j=0;j<=n;j++){
			cin>>a;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<n;i++){
			maxn=a;
			if(maxn<a[i+1][j]){
				minn=maxn;
				maxn=a[i+1][j];
				num1+a[i+1][j];
			}
			else{
				num2+a[i+1][j];
				continue;
			}
		}
	}
	else (num2>n/=2){
		num-minn;
	}
		if(num1>n/=2){
		num-minn;
		for(int i=1;i<n;i++){
			for(int j=2;j<=i;j++){
				if(a[i][j]>a[i][j+1]){
					num2++;
				}
				else{
					num3+=a[i][j+1];
				}
			}
		}
	}
 else if(num2>n/=2){
		num-minn;
		for(int i=1;i<n;i++){
			for(int j=1;j<=i;j++){
				if(a[i][j]>a[i][j-1]){
					num2++;
				}
				else{
					num3+=a[i][j-1];
					
			}
		}
	}
	}
	cout<<n;
	return 0;
}
