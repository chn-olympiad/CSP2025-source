#include<bits/stdc++.h>
using namespace std;
int n,sum,flag=1;
int a[5010];
void dfs_3(int x,int y,int z){
//	cout<<x<<' '<<y<<' '<<z<<endl;
	if(a[x]+a[y]>a[z]){
		sum++;
	}
	if(z==n){
		if(y==n-1){
			if(x==n-2){
				return;
			}else{
				dfs_3(x+1,x+2,x+3);
			}
		}else{
			dfs_3(x,y+1,y+2);
		}
	}else{
		dfs_3(x,y,z+1);
	}
	return;
}
void dfs_4(int w,int x,int y,int z){
	if(a[w]+a[x]+a[y]>a[z]){
		sum++;
	}
	cout<<w<<' '<<x<<' '<<y<<' '<<z<<endl;
	if(z>=n){
		if(y>=n-1){
			if(x>=n-2){
				if(w>=n-3){
					return;
				}else{
					dfs_4(w+1,w+2,w+3,w+4);
				}
			}else{
				dfs_4(w,z+1,z+2,z+3);
			}
		}else{
			dfs_4(w,x,y+1,y+2);
		}
	}else{
		dfs_4(w,x,y,z+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			flag=0;
		}
	}
	if(flag){
		sum=1;
		for(int i=n;i>=1;i--){
			sum=sum*i%998%244%353;
		}
		cout<<sum%998%244%353;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		dfs_3(1,2,3);
		cout<<sum%998%244%353;
	}else if(n==4){
		dfs_3(1,2,3);
		if(a[1]+a[2]+a[3]>a[4]){
			sum++;
		}
		cout<<sum%998%244%353;
	}else{
		dfs_3(1,2,3);
		dfs_4(1,2,3,4);
		if(a[1]+a[2]+a[3]+a[4]>a[5]){
			sum++;
		}
		cout<<sum%998%244%353;
	}
	return 0;
}
