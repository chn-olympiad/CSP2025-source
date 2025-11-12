#include<bits/stdc++.h>
using namespace std;
int t,n,a1,b1,c1,ans;
bool f;
struct node{
	int a,b,c;
	bool s1=0,s2=0,s3=0;
}p[100001];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a==max(p[i].c,max(p[i].a,p[i].b))){
				p[i].s1=1;
				a1++;
			}
			else if(p[i].b==max(p[i].c,max(p[i].a,p[i].b))){
				p[i].s2=1;
				b1++;
			}
			else {
				p[i].s3=1;
				c1++;
			}
			if(p[i].b==p[i].c&&p[i].b==0)continue;
			else f=1;
		}
		if(a1<=n/2&&b1<=n/2&&c1<=n/2){
			for(int i=1;i<=n;i++){
				if(p[i].s1)ans+=p[i].a;
				else if(p[i].s2)ans+=p[i].b;
				else ans+=p[i].c;
			}
		}
		else if(!f){
			sort(p+1,p+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
		}
		else if(f){
			ans=max(ans,p[1].a+p[2].b);
			ans=max(ans,p[1].a+p[2].c);
			ans=max(ans,p[1].b+p[2].c);
		}	
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
