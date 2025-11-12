#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,c[5005],ans;
void dg(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=ans;i++)sum+=c[i];
		if(sum>c[ans]*2)s++;
		return;
	}dg(x+1);
	c[++ans]=a[x];
	dg(x+1);
	ans--;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);dg(1);cout<<s;
	return 0;
}
