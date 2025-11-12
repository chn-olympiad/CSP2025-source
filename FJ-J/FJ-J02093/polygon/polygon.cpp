#include <bits/stdc++.h>
using namespace std; 
int a[5005];
int n;
int ans=0;
int dfs(int h,int max1,int num,int x,int y){
	if(x>n){
		if(num==y){
			if(h>max1*2){
				return 1;
			}else{
				return 0;
			}
		} else{
			return 0;
		}
	}
	if(num==y){
		if(h>max1*2){
			return 1;
		}else{
			return 0;
		}
	} 
	int max2=max(max1,a[x]);
	return dfs(h+a[x],max2,num+1,x+1,y)+dfs(h,max1,num,x+1,y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		int d=a[3],c=a[1]+a[2];
		if(c>d){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		ans+=dfs(0,0,0,1,i)%998244353;
	}
	cout<<ans;
	return 0;
}
