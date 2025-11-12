#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[100005],b[100005],c[100005],d[15],e[1005],cnt=0;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i=0;i<k;i++){
		cin >> d[i];
		for(int j=0;j<n;j++){
			cin >> e[1005];
		}
	}
	if(k==0){
		for(int i=0;i<n;i++){
			cnt+=c[i];
		}
		cout << cnt;
	}else{
		int cc11=0,dd11=INT_MAX;
		for(int i=0;i<n;i++){
			if(c[i]>cc11){
				cc11=c[i];
			}
			if(d[i]<dd11){
				dd11=d[i];
			}
		}
		cout << cc11+dd11;
	}
	return 0;
}
