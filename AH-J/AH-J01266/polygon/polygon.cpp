#include<bits/stdc++.h>
using namespace std;
int n,cnt,xx;
int a[5005];
int v[5005][5005];
int cd(int x){
	int ans=0;
	for(int i=0;v[x][i]!=0;i++){
		ans++;
	}
	return ans;
}
int check(int x,int y){
	int c[5005];
	int j=0;
	for(int i=1;i<x;i++){
		c[j]=a[i];
		j++;
	}
	for(int i=y;i<=n;i++){
		c[j]=a[i];
		j++;
	}
	for(int i=0;i<xx;i++){
		if(cd(i)!=j-1){
			break;
		}
		int ans=0;
		for(int z=0;z<j;z++){
			if(c[z]==v[i][z]){
				ans++;
			}
		}
		if(ans==j-1){
			return 1;
		}
	}
	return 0;
}
void jj(int x,int y){
	int j=0;
	for(int i=1;i<x;i++){
		v[xx][j]=a[i];
		j++;
	}
	for(int i=y;i<=n;i++){
		v[xx][j]=a[i];
		j++;
	}
	return ;
}
int he(int x,int y,int z){
	long long ans=0;
	for(int i=x;i<=y;i++){
		ans+=a[i];
	}
	for(int i=1;i<z;i++){
		ans+=a[i];
	}
	return ans;
}
int ma(int x,int y,int z){
	int ans=-1;
	for(int i=x;i<=y;i++){
		if(a[i]>ans){
			ans=a[i];
		}
	}
	for(int i=1;i<z;i++){
		if(a[i]>ans){
			ans=a[i];
		}
	}
	return ans;
}
void b(int x){
	if(x>n){
		return ;
	}
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(n-j+x<3){
				continue;
			}
			long long h=he(j,n,x);
			int maxx=ma(j,n,x);
			if(h>maxx*2&&check(x,j)==0){
				cnt++;
				jj(x,j);
				xx++;
			}
		}
	}
	b(x+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		long long h=a[1]+a[2]+a[3];
		int maxx=max(a[1],max(a[2],a[3]));
		if(h>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	b(0);
	cout<<cnt;
	return 0;
}
