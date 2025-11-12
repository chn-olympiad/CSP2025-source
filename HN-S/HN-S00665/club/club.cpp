#include<bits/stdc++.h>
using namespace std;
int m1[100001],m2[100001],m3[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int p=0,mw=0;
		cin>>p;
		for(int j=0;j<p;j++){
			scanf("%d%d%d",&m1[j],&m2[j],&m3[j]);
		}
		sort(m1,m1+p);
		for(int j=p-1;j>=p/2;j--){
			mw+=m1[j];
		}
		printf("%d\n",mw);
	}
	return 0;
}
