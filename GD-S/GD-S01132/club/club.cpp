#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int id;
};
int b[100010][5];
node a[100010];
int n;
bool cmp(node x,node y){
	if((x.c-x.b)==(y.c-y.b)){
		return (x.b-x.a)>(y.b-y.a);
	}
	return (x.c-x.b)>(y.c-y.b);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].id=i;
		b[i][1]=a[i].a;
		b[i][2]=a[i].b;
		b[i][3]=a[i].c;
	}
	for(int i=1;i<=n;i++){
		if(a[i].a>a[i].b){
			int c=a[i].a;
			a[i].a=a[i].b;
			a[i].b=c;
		}
		if(a[i].b>a[i].c){
			int c=a[i].b;
			a[i].b=a[i].c;
			a[i].c=c;
		}
		if(a[i].a>a[i].b){
			int c=a[i].a;
			a[i].a=a[i].b;
			a[i].b=c;
		}
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	int aa=0,bb=0,cc=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int k=1;k<=3;k++){
			if(a[i].c==b[a[i].id][k]){
				u=k;
				break;
			}
		}
		if(u==1&&aa!=n/2){
			ans+=a[i].c;
			aa++;
			continue;
		}
		if(u==2&&bb!=n/2){
			ans+=a[i].c;
			bb++;
			continue;
		}
		if(u==3&&cc!=n/2){
			ans+=a[i].c;
			cc++;
			continue;
		}
		
		for(int k=1;k<=3;k++){
			if(a[i].b==b[a[i].id][k]&&k!=u){
				u=k;
				break;
			}
		}
		if(u==1&&aa!=n/2){
			ans+=a[i].b;
			aa++;
			continue;
		}
		if(u==2&&bb!=n/2){
			ans+=a[i].b;
			bb++;
			continue;
		}
		if(u==3&&cc!=n/2){
			ans+=a[i].b;
			cc++;
			continue;
		}
		
		for(int k=1;k<=3;k++){
			if(a[i].c==b[a[i].id][k]&&k!=u){
				u=k;
				break;
			}
		}
		if(u==1&&aa!=n/2){
			ans+=a[i].c;
			aa++;
			continue;
		}
		if(u==2&&bb!=n/2){
			ans+=a[i].c;
			bb++;
			continue;
		}
		if(u==3&&cc!=n/2){
			ans+=a[i].c;
			cc++;
			continue;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
