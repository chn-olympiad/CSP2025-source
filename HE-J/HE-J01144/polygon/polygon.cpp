#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a<b;
}
int a[5555],b[5555];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	if (n<3){
		cout<<0;return 0;
	}
	int sum=0,ans=0;
	sort(b+1,b+n+1,cmp);
	int x=b[n]*2;
	for(int i=1;i<=n;++i){
		ans+=a[i];
	}
		if (ans>x){
			cout<<1;return 0;
		}
		else {
			cout<<0;return 0;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
