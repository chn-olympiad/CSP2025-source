#include<bits/stdc++.h>
using namespace std;
const int INT=998244353;
int n,a[5010],s,m,b,f=1;
long long ans;
void xh(int g,int d){
	g--;
	for(int i=d+1;i<n;i++){
		s+=a[i];
		b=m;
		if(m<a[i]){
			f=0;
			m=a[i];
		}
		if(g==0){
			if(s>m*2) ans++;
			d--;
			s-=a[i];
			if(f==0) m=b;
		}else{
			xh(g,i);
		}
	}
	g++;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int g=3;g<=n;g++){
		s=0,m=0;
		xh(g,-1);
	}
	ans-=4;
	cout<<ans%INT;
	return 0;
}