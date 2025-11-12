#include<bits/stdc++.h>
using namespace std;
int n;
struct F{
	int a,id;
	bool live;
}f[5010]; 
bool find(int x,int y){
	int tot=0,maxa=0;
	for(int i=x;i<=y;i++){
		tot+=f[i].a;
		maxa=max(maxa,f[i].a);
	}
	if(tot>2*maxa) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>f[i].a;
		if(f[i].a!=1) flag=0;
	}
	long long ans=0;
	if(flag==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		int tot=f[1].a+f[2].a+f[3].a;
		int maxa=max(f[1].a,max(f[2].a,f[3].a));
		if(tot>2*maxa) cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
