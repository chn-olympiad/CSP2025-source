//我太废了，明年再战QAQ 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int a[100010][3];

struct asdf{
	int v,id;
}b[100010];
bool cmp(asdf x,asdf y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int i;
		bool flg=1;
		for(i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1])flg=0;
			b[i].v=a[i][0]-a[i][1];
			b[i].id=i;
		}int ans=0;
		if(!flg){
			
			sort(b+1,b+1+n,cmp);
			
			for(i=1;i<=n;i++){
				if(i<=n/2){
					ans+=a[b[i].id][0];
				}else{
					ans+=a[b[i].id][1];
				}
			}
		}else{
			for(i=1;i<=n;i++)ans+=a[i][0]; 
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
