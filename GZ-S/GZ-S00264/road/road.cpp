//GZ-S00264 YangChengjin HLXX
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ds,sum,minn=INT_MAX; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m*3;i++)cin>>ds;//占位
	for(int i=1;i<=k;i++){
		for(int i=0;i<=n;i++){
			cin>>ds;
			sum+=ds;
		}
		minn=min(minn,sum);
	} 
	cout<<minn<<"\n";
	return 0;//by-ycj
}
//造一朵菊花 
