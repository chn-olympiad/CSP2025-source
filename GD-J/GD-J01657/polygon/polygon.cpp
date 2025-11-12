#include<bits/stdc++.h>
using namespace std;
int n,a[5005],z;
void sh(int zongc,int zuic,int shu,int io){
	if(shu<3){
		for(int o=io;o<=n;o++){
			sh(zongc+a[o],a[o],shu+1,o);
		}
	}
	else if(zongc>2*zuic){
		z=(z+1)%998244353;
		for(int o=io;o<=n;o++){
			sh(zongc+a[o],a[o],shu+1,o);
		}
	}
	else{
		for(int o=io;o<=n;o++){
			sh(zongc+a[o],a[o],shu+1,o);
		}
	}
}
bool cmp(int x,int y){
	return x<y;
} 
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		//int o;
		cin>>a[i];
	    //a[o]++;
	}
	sort(a+1,a+n+1,cmp);
	sh(0,0,0,1);
	cout<<z;
	return 0;
} 
