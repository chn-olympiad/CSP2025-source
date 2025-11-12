#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		if(n==2){
			int s[4]={0,0,0,0};
			int s2[4]={0,0,0,0};
			for(int i=1;i<=3;i++){
				cin>>s[i];
			}
			for(int i=1;i<=3;i++){
				cin>>s2[i];
			}
			int maxn=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxn=max(maxn,s[i]+s2[j]);
					}
				}
			}
			cout<<maxn<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=x;
		}
		int sum=0;
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
			sum+=a[i];
		}
		cout<<sum<<"\n";
	}
}
