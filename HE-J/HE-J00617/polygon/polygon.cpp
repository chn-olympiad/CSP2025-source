#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],js=0;
void fa(long long h,int zc,int gs){
	if(h>2*a[zc]&&gs>=3){
		js++;
		js%=998244353;
		return ;
	}
	for(int i=zc+1;i<=n;i++){
		fa(h+a[i],i,gs+1);
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
	fa(0,0,0);
	cout<<js;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
