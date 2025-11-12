#include<bits/stdc++.h>
using namespace std;
long long n,a[100050],x,s,ans,b[100414];
void df(int i,int last){
	if(i==x+1){
		long long h=0,maxx=0;
		for(int j=1;j<=x;j++){
			//cout<<b[j]<<' ';
			h+=b[j];
			maxx=max(maxx,b[j]);
		}
		//cout<<endl;
		if(h>maxx*2){
			ans++;
			//cout<<h<<' '<<maxx<<' '<<s<<endl;
		}
		return;
	}
	for(int j=last+1;j<=n;j++){
		b[i]=a[j];
		df(i+1,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		x=i,s=0;
		df(1,0);
	}
	cout<<ans;
	return 0;
}