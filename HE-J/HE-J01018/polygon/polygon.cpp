#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1,g=r;
	while(l<=r){
		int x=l+1,y=l+1,lm=s[r]-s[l-1],z=y;
		while(x<=y&&r-l>=2){
			int xm=s[y]-s[x-1];
			if(lm-xm>a[r]*2&&(r-l+1)-(y-x+1)>=3){
				ans++;
//				cout<<lm-xm<<" "<<l<<" "<<r<<"|"<<x<<" "<<y<<endl;
			}
			if(y==r){
				y=z;
				z++;
				x++;
			}
			y++;
			if(x==r||(y==r&&z==r)){
				break;
			}
		}
		if(lm>a[r]*2){
			ans++;
//			cout<<lm<<" "<<l<<" "<<r<<endl;
		}
		if(r==n){
			r=g;
			g++;
			l++;
		}
		r++;
		if(l==n||(r==n&&g==n)) break;
	}
	cout<<ans;
	return 0;
}
