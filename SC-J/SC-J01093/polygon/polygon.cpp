#include<bits/stdc++.h>
using namespace std;
int n,a[5002];
int p(int x,int y,int e){
	int ans=x,m=x,q=0,cnt=e;
	for(int i=y+1;i<=n;i++){
		cnt++;
		ans+=a[i];
		m=a[i];
		if(cnt>=3){
			if(ans>m*2){
				q++;
			}
		}
		if(cnt==n) q+=p(ans,i,1);
		else q+=p(ans,i,cnt);
	}
	return q;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int q=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		q+=p(a[i],i,1);
	}
	cout<<q;
	return 0;
} 