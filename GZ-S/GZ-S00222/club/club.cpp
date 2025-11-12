//GZ-S00222 贵阳市新世界学校 李宗运 
#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct node{
	int mx,mi,a,b,c;
};

void ddf(node &aa,int i){
	if(aa.a>aa.mx){
		aa.mi=1,aa.mx=aa.a;
	}
	if(aa.b>aa.mx){
		aa.mi=2,aa.mx=aa.b;
	}
	if(aa.c>aa.mx){
		aa.mi=3,aa.mx=aa.c;
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		node aa[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			ddf(aa[i],i);
			ans+=aa[i].mx;
		}
		cout<<ans;
	}
	return 0;
}
