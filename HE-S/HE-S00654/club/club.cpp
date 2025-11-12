#include<bits/stdc++.h>
using namespace std;
int t,n;
struct str{
	int id,a,b,c,d;
}p[100010];
bool cmp(str l,str r){
	if(l.d==r.d){
		if(l.a==r.a){
		if(l.b==r.b){
			return l.c>r.c;
		}
		return l.b>r.b;
	}
	return l.a>r.a;
	}
	return l.d>r.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x=0,y=0,z=0;
			cin>>x>>y>>z; 
			p[i].id=i;
			p[i].a=x;
			p[i].b=y;
			p[i].c=z;
			p[i].d=max(x,max(y,z));
		}
		sort(p+1,p+n+1,cmp);
		int a11=0,b11=0,c11=0;
		int mid=(n>>1);
		for(int i=1;i<=n;i++){
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c&&a11+1<=mid){
				if(a11+1==mid){
					if(b11+1<=mid&&p[i+1].b>=p[i+1].c){
						if(p[i].a+p[i+1].b>=p[i].b+p[i+1].d){
						ans+=p[i].a,a11++;}
						else {
						ans+=p[i].b;
						b11++;
					}
					}
					else if(c11+1<=mid){
						if(p[i].a+p[i+1].b>=p[i].b+p[i+1].d){
						ans+=p[i].a,a11++;}
						else {
						ans+=p[i].b;
						b11++;
					}
					}
					else {
						ans+=p[i].a;a11++;
					}
				}
				else{
					ans+=p[i].a;
					a11++;
				}
			}
			else{
				
				if(p[i].b>=p[i].c&&b11+1<=mid){
					ans+=p[i].b;
					b11++;
				}
				else{
					ans+=p[i].c;
					c11++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
