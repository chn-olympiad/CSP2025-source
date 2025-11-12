#include<bits/stdc++.h>
using namespace std;
int n,m,mp[105][105],a[1005],ism;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	ism=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=n*m;j>=1;j--){
			if(a[j]<a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	int id=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[id];
				if(a[id]==ism) {
					cout<<i<<" "<<j;
					return 0;
				}
				id++;
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[id];
				if(a[id]==ism){
					cout<<i<<" "<<j;
					return 0;
				}
				id++;
			}
		}
	}
	return 0;
}