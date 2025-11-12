#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,xx,yy;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+k+1);
	for(int i=k;i>=1;--i){
		if(a[i]==ans){
			cnt=k-i+1;
		}
	}
	xx=(cnt+n-1)/n;
	int po=cnt%n;
	if(xx%2==0){
		if(po==0){
			yy=1;
		}
		else yy=n+1-po;
	}
	else{
		if(po==0){
			yy=n;
		}
		else yy=po;
	}
	cout<<xx<<" "<<yy;
    fclose(stdin);
	fclose(stdout);
	return 0;
}