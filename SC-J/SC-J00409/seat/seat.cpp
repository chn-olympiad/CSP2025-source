#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n,m,c,r,v,t,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	v=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				cnt=a[i];
				a[i]=a[j];
				a[j]=cnt;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			cnt=i;
			break;
		}
	}
	c=ceil((float)cnt/n);
	if(c%2==0){
		r=n*c-cnt+1;
	}else {
		r=cnt%n;
		if(r==0) r=n;
	}
	cout<<c<<" "<<r;
	return 0;
} 