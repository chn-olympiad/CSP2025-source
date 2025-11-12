#include<bits/stdc++.h>
using namespace std;
int sz[500005], sz1[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int i, n, j, t, ans=0, max1=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>sz[i];
		sz1[i]=sz[i];
	}
	for(i=1;i<=n;i++){
		sz[i]=sz[i]+sz[i-1];
	}
	for(i=2;i<=n;i++){
		for(j=1;j+i<=n;j++){
			max1=0;
			for(t=0;t<i;t++){
				max1=max(max1,sz1[j+t]);
			}
			if(sz[j+i-1]-sz[j-1]>max1*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
