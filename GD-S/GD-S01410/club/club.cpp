#include<bits/stdc++.h>
using namespace std;
struct Club{
	int a,b,c;
}clubs[100005];
int T,n;
bool cmp(Club x,Club y){
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int suma=0,sumb=0,sumc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>clubs[i].a>>clubs[i].b>>clubs[i].c;
		}
		sort(clubs+1,clubs+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(max(clubs[i].a,max(clubs[i].b,clubs[i].c))==clubs[i].a&&suma<n/2){ 
				ans+=clubs[i].a;
				suma++;
			}
			else if(max(clubs[i].a,max(clubs[i].b,clubs[i].c))==clubs[i].b&&sumb<n/2){ 
				ans+=clubs[i].b;
				sumb++;
			}
			else{
				ans+=clubs[i].c;
				sumc++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
