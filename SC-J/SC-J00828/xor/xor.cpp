#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,k;
int a[N];
bool flag=true;
vector<vector<int> > v(20005,vector<int>(20005));
int js(int x,int y){
	return (x|y)-(x&y);
}
bool check(int tar){
	int cnt=0;
	int ri,rj;
	ri=rj=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
//			cout<<i<<" "<<j<<" ";
			if(flag && v[i][j]==0){
//				cout<<"shi1 ";
				if(i==j) v[i][j]=a[i];
			    else v[i][j]=js(v[i-1][j],a[i]);
			    if(i==n && j==n){
			    	flag=false;
//			    	for(int s=1;s<=n;s++){
//			    		for(int t=1;t<=s;t++){
//			    			cout<<v[s][t]<<" ";
//						}
//						cout<<endl;
//					}
				}
			}
//			cout<<v[i][j]<<endl;
			if(v[i][j]==k && i>ri && j>ri){
				cnt++;
				ri=i;
				rj=j;
				if(cnt>=tar) return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
  //  cout<<"kaishi"<<endl;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l,r;
	l=0,r=n;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
//		cout<<mid<<endl;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ans!=-1) cout<<ans;
	return 0;
}