#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
}a[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=0;
	}
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		for(int l=1;l<=n&&l+i-1<=n;l++){
			if(a[l].y==1)continue;
			r=l+i-1;
			int num=a[l].x;
			int  c=1;
			for(int j=l+1;j<=r;j++){
				num^=a[j].x;
				if(a[j].y==1){
					c=0;
					break;
				}
			}
			if(num==k&&c==1){
				for(int j=l;j<=r;j++){
					a[j].y=1;
				}
				l=r+1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

