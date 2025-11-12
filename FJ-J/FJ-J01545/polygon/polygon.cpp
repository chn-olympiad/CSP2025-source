#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			for(int k=i;k<=j;k++) l=l+a[k];
			if(l>a[i]*2) t++;
			l=0;
		}
	}
	cout<<t;
	return 0;
}


