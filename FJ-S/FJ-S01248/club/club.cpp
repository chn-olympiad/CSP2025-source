#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans[100005],o=0,t=0,e=0,sum=0;
		cin>>n;
		struct JK{
			int a,b,c,k,l;
		}s[100005];
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b){
				if(s[i].a>s[i].c){
					if(s[i].c>s[i].b){
						s[i].l=3;
					}else{
						s[i].l=2;
					}
					s[i].k=1;
					o++;
				}else{
					s[i].k=3;
					s[i].l=1;
					e++;
				}
			}else{
				if(s[i].b>s[i].c){
					if(s[i].a>s[i].c){
						s[i].l=1;
					}else{
						s[i].l=3;
					}
					s[i].k=2;
					t++;
				}else{
					s[i].k=3;
					s[i].l=2;
					e++;
				}
			}
		}
		int onee=0,twoo=0,threee=0;
		for(int i=1;i<=n;i++){
			if(s[i].k==1){
				onee+=s[i].a;
			}
			if(s[i].k==2){
				twoo+=s[i].b;
			}
			if(s[i].k==3){
				threee+=s[i].c;
			}
		}
		if(o<=n/2&&(t<=n/2&&e<=n/2)){
			sum+=onee+twoo+threee;
		}else{
			if(o>n/2){
				int p=onee+twoo+threee;
				for(int j=1;j<=o-n/2;j++){
					int na=0,minn=INT_MAX;
					for(int i=1;i<=n;i++){
						if(s[i].k==1){
							if(s[i].l==2){
								na=s[i].a-s[i].b;
							}
							if(s[i].l==3){
								na=s[i].a-s[i].c;
							}
						}
						minn=min(minn,na);
					}
					for(int i=1;i<=n;i++){
						if(s[i].k==1){
							if(s[i].l==2){
								if(minn==s[i].a-s[i].b){
									s[i].k=0;
									break;
								}
							}
							if(s[i].l==3){
								if(minn==s[i].a-s[i].c){
									s[i].k=0;
									break;
								}
							}
						}
					}
					p-=minn;	
				}
				sum+=p;
			}


			if(t>n/2){
				int p=onee+twoo+threee;
				for(int j=1;j<=t-n/2;j++){
					int na=0,minn=INT_MAX;
					for(int i=1;i<=n;i++){
						if(s[i].k==2){
							if(s[i].l==1){
								na=s[i].b-s[i].a;
							}
							if(s[i].l==3){
								na=s[i].b-s[i].c;
							}
						}
						minn=min(minn,na);
					}
					for(int i=1;i<=n;i++){
						if(s[i].k==2){
							if(s[i].l==1){
								if(minn==s[i].b-s[i].a){
									s[i].k=0;
									break;
								}
							}
							if(s[i].l==3){
								if(minn==s[i].b-s[i].c){
									s[i].k=0;
									break;
								}
							}
						}
					}
					p-=minn;	
				}
				sum+=p;
			}

			if(e>n/2){
				int p=onee+twoo+threee;
				for(int j=1;j<=e-n/2;j++){
					int na=0,minn=INT_MAX;
					for(int i=1;i<=n;i++){
						if(s[i].k==3){
							if(s[i].l==1){
								na=s[i].c-s[i].a;
							}
							if(s[i].l==2){
								na=s[i].c-s[i].b;
							}
						}
						minn=min(minn,na);
					}
					for(int i=1;i<=n;i++){
						if(s[i].k==3){
							if(s[i].l==1){
								if(minn==s[i].c-s[i].a){
									s[i].k=0;
									break;
								}
							}
							if(s[i].l==2){
								if(minn==s[i].c-s[i].b){
									s[i].k=0;
									break;
								}
							}
						}
					}
					p-=minn;	
				}
				sum+=p;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 


