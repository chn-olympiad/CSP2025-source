#include<bits/stdc++.h>
using namespace std;
int n,a[10],maxx=0,cut=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		cut+=a[i];
	}
	if(n<3){
		cout<<"0";
	}else{
		if(maxx*2<cut){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
