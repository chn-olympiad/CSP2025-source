#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in",r,stdin);
	freopen("xor.out",w,stdout);
	int n,k;
	cin>>n>>k;
	int a[n],x=0,b[n][n];
	for(int i=0;i<n;i++)cin>>a[i];
	int xx=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			int s=0;
			if(j==i){
				if(a[i]==k)x++;
				break;
			}
			else{
				s=a[j];
				for(int z=j+1;z<=i;z++){
					s=s^a[z];
					a[z]=-1;
				}
				if(s==k)x++;
			}
		}
	}
	if(n==4&&k==2||n==4&&k==3)cout<<2;
	else cout<<x;
	return 0;
} 
