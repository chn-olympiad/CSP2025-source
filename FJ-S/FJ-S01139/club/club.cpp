#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
struct s{
	int a,b,c;
	bool aaa=false,bbb=false,ccc=false;
}go[100005];
int aaa[100005],bbb[100005],ccc[100005];
bool cmp(s x,s y){
	return x.a>y.a;
}
bool cmpb(s x,s y){
	return x.b>y.b;
}
bool cmpc(s x,s y){
	return x.c>y.c;
}
int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int z=1;z<=t;z++){
		int n,ans=0,A=0,B=0,C=0;
		cin>>n;
		bool aa=false,bb=false,cc=false;
		for(int i=1;i<=n;i++){
			cin >> go[i].a >> go[i].b >> go[i].c;
			if(go[i].a){
				aa=true;
			}
			if(go[i].b){
				bb=true;
			}
			if(go[i].c){
				cc=true;
			}
			if(go[i].a>=go[i].b && go[i].a>=go[i].c){
				go[i].aaa=true;
				A++;
			}else if(go[i].b>=go[i].a && go[i].b>=go[i].c){
				go[i].bbb=true;
				B++;
			}else{
				go[i].ccc=true;
				C++;
			}
		}
		if(bb==false && cc==false){
			sort(go+1,go+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=go[i].a;
			}
		}else if(cc==false){
			if(A<=n/2 && B<=n/2){
				for(int i=1;i<=n;i++){
					if(go[i].aaa==true){
						ans+=go[i].a;
					}else{
						ans+=go[i].b;
					}
				}
			}else if(A>n/2){
				sort(go+1,go+n+1,cmp);
				A=0;
				for(int i=1;i<=n;i++){
					if(go[i].aaa==true && A<n/2){
						ans+=go[i].a;
						A++;
					}else{
						ans+=go[i].b;
					}
				}
			}else{
				sort(go+1,go+n+1,cmpb);
				B=0;
				for(int i=1;i<=n;i++){
					if(go[i].bbb==true && B<n/2){
						ans+=go[i].b;
						B++;
					}else{
						ans+=go[i].a;
					}
				}
			}
		}else{
			if(A<=n/2 && B<=n/2 && C<=n/2){
				for(int i=1;i<=n;i++){
					if(go[i].aaa==true){
						ans+=go[i].a;
					}else if(go[i].bbb==true){
						ans+=go[i].b;
					}else{
						ans+=go[i].c;
					}
				}
			}else if(A>n/2){
				A=0;
				sort(go+1,go+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(go[i].aaa==true && A<n/2){
						ans+=go[i].a;
						A++;
					}else{
						ans+=max(go[i].b,go[i].c);
					}
				}
			}else if(B>n/2){
				B=0;
				sort(go+1,go+n+1,cmpb);
				for(int i=1;i<=n;i++){
					if(go[i].bbb==true && B<n/2){
						ans+=go[i].b;
						B++;
					}else{
						ans+=max(go[i].a,go[i].c);
					}
				}
			}else{
				C=0;
				sort(go+1,go+n+1,cmpc);
				for(int i=1;i<=n;i++){
					if(go[i].ccc==true && C<n/2){
						ans+=go[i].c;
						C++;
					}else{
						ans+=max(go[i].a,go[i].b);
					}
				}
			}
		}
		cout<<ans << endl;
	}
	return 0;
}
