#include<bits/stdc++.h>
using namespace std;
int n,t,jg,g1,g2,g3;
struct ccc{
	int a,b,c;
	int fp;
}p[100005];
bool cmp(ccc x,ccc y){
	if(x.a<y.a){
		return true;
	}else if(x.a==y.a){
		if(x.b<y.b)
			return true;
		else if(x.b==y.b)
		    return x.c<y.c;
	}return false; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	while(t--){
		cin>>n; jg=g1=g2=g3=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}sort(p+1,p+n+1,cmp);
		/*cout<<"ÅÅÐòºó\n"; 
		for(int i=1;i<=n;i++){
			cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<endl;
		}*/
		for(int i=1;i<=n;i++){
			if(p[i].a>p[i].b&&p[i].a>p[i].c){
				if(g1==n/2){
					if(p[i].b>p[i].c&&g2<n/2){
						g2++;jg+=p[i].b;
					}else{
						g3++;jg+=p[i].c;
					}
				}else{
					/*fp=1;*/ g1++;jg+=p[i].a;
				}
			}else if(p[i].b>p[i].a&&p[i].b>p[i].c){
				if(g2==n/2){
					if(p[i].a>p[i].c&&g1<n/2){
						g1++;jg+=p[i].a;
					}else{
						g3++;jg+=p[i].c;
					}
				}else{
					/*fp=1;*/ g2++;jg+=p[i].b;
				}
			}else if(p[i].c>p[i].a&&p[i].c>p[i].b){
				if(g3==n/2){
					if(p[i].a>p[i].b&&g1<n/2){
						g1++;jg+=p[i].a;
					}else{
						g2++;jg+=p[i].b;
					}
				}else{
					/*fp=1;*/ g3++;jg+=p[i].c;
				}
			}
		}cout/*<<"jg="*/<<jg<<endl;
	}
	return 0; 
} 
