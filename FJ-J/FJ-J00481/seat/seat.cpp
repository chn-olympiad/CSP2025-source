#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
ll f[1005][1005],n,a[N],xc,cnt=1,m;
bool flag=false;
bool cmp(int a,int b){
	return a>b;
}
bool pd(int a){
	if(a==xc) return true; 
	else return false;
}
int main(){
	freopen("seat","w",stdin);
	freopen("seat","r",stdout);	
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	xc=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(m%2==1) m--; flag=true;
	cnt=1;
	for(ll i=1;i<=m;i+=2){
		for(ll j=1;j<=n;j++){
			f[i][j]=a[cnt];
			if(pd(a[cnt])==true){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
			cnt++;
		}
		for(ll j=n;j>=1;j--){ 
			f[i+1][j]=a[cnt];
			if(pd(a[cnt])==true){
				cout<<i+1<<' '<<j<<endl;
				return 0;
			}
			cnt++;
		}
		if(i+2>=n) break;
	}
	if(flag=true){
		for(ll j=1;j<=n;j++){
			f[m+1][j]=a[cnt];
			if(pd(a[cnt])==true){
				cout<<m+1<<' '<<j<<endl;
				return 0;
			}
			cnt++;
		}	
	}
	return 0;
}
