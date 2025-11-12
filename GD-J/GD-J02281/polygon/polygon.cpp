#include<bits/stdc++.h>
using namespace std;
bool w;
int n,a[5005],b[5005],z,I,l,c[5005],num;
int dfs(int x) {
	w=false;
	if(x==I+1) {
		z=0;
		for(int i=l-1; i>=1; i--) {
			if(c[i]<c[i-1]||b[i]==b[i-1]){
				return 0;
			}
			z+=b[i];
		}
		/*---------------------------------------------------
		for(int i=1; i<=l; i++) {
			cout<<" b["<<i<<"]="<<b[i];
		}
		cout<<endl;
		for(int i=1; i<=l; i++) {
			cout<<" c["<<i<<"]="<<c[i];
		}
		cout<<endl<<endl;
		//---------------------------------------------------*/
		if(z>b[l]) {
			num++;
			num%=998244353;
		}else{
			w=true;
		}
		return 0;
	}
	for(int i=x; i<=n; i++) {
		l++;
		b[l]=a[i];
		c[l]=i;
		dfs(x+1);
		c[l]=0;
		l--;
		b[i]=0;
		//*
		if(w){
			w=false;
			return 0;
		}
		//*/
	}
	return 0;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(I=1; I<=n; I++) {
		scanf("%d",&a[I]);
	}
	sort(a+1,a+1+n);
	for(I=3; I<=n; I++) {
		dfs(1);
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
