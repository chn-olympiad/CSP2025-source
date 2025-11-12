#include <bits/stdc++.h>
using namespace std;
int a[5005];int n;
//struct hh{
//	int num,xx;
//}a[5005];
//bool cmp(hh x,hh y){
//	return x.num<yy.num;
//}
int ans;
void js(int now,int kk,int pluss,int xb){
	for(int i=xb+1;i<n;i++){
		if(now==kk){
			pluss+=a[i];
			
			if(pluss>a[i]*2){
				ans++;
				pluss-=a[i];
//				cout<<now<<' '<<pluss<<' '<<a[i]<<'\n';
			}
			else break;
		}
		else{
			js(now+1,kk,pluss+a[i],i);
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int g=3;
	while(g<=n){
		js(1,g,0,-1);
		g++;
	}
	cout<<ans;
	return 0;
}