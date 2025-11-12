//GZ-S00442 郑景元 贵阳市中天中学 
#include<bits/stdc++.h>
using namespace std;
int n,t,cnt=0,k,m,maxx,d;
long long a[100005][3],b[3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int c[3]={0,0,0};
	for(int i=1;i<=t;i++){
		cin>>n;
		m=n/2;
		cnt=0;
		for(int j=0;j<n;j++){
			maxx=0;
			for(k=0;k<=2;k++){
				cin>>a[j][k];
				if(maxx<a[j][k]&&c[k]<=m){
					maxx=a[j][k];
					d=k;
				}else{
					maxx=max(a[j][k-1],a[j][k-2]);
					if(a[j][k-1]>a[j][k-2])d=k-1;
					else d=k-2;
				}
			}
			c[d]+1;
			cnt+=maxx;
		}
		cout<<cnt<<endl; 
	}
	return 0;
}
