//GZ-S00210 贵阳市第一中学 朱九萌 
#include<bits/stdc++.h>
#define NN 100005
#define int long long
using namespace std;
int t,n,a1,a2,a3;
struct xyz{
	int a,b,c;
}p[NN];
bool cmp(xyz st,xyz nd){
	if(st.a==nd.a){
		if(st.b==nd.b){
			return st.c<nd.c;
		}
		return st.b<nd.b;
	}
	return st.a<nd.a;
}
bool cmp1(xyz st,xyz nd){
	if(st.a==nd.a){
		if(st.b==nd.b){
			return st.c>nd.c;
		}
		return st.b>nd.b;
	}
	return st.a>nd.a;
}
bool cmp2(xyz st,xyz nd){
	if(st.a==nd.a&&st.b==nd.b){
		return st.c>nd.c;
	}else if(st.a==nd.a&&st.c==nd.c){
		return st.b>nd.b;
	}else if(st.b==nd.b&&st.c==nd.c){
		return st.a>nd.a;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		a1=0;
		a2=0;
		a3=0;
		memset(p,sizeof(p),0);
		int an=0,bn=0,cn=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a==0){
				an++;
			}
			if(p[i].b==0){
				bn++;
			}
			if(p[i].c==0){
				cn++;
			}
		}
		if(an+bn+cn==2*n){
			sort(p+1,p+1+n,cmp2);
			int cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt+=p[i].a;
				cnt+=p[i].b;
				cnt+=p[i].c;
			}
			cout<<cnt<<"\n";
			continue;
		}
		int ans1=0;
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
				if(a1<=n/2-1){
					a1++;
					ans1+=p[i].a;
				}else{
					if(p[i].b>=p[i].c){
						if(a2<=n/2-1){
							a2++;
							ans1+=p[i].b;
						}else{
							a3++;
							ans1+=p[i].c;
						}
					}else{
						if(a3<=n/2-1){
							a3++;
							ans1+=p[i].c;
						}else{
							a2++;
							ans1+=p[i].b;
						}
					}
				}
			}
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c){
				if(a2<=n/2-1){
					a2++;
					ans1+=p[i].b;
				}else{
					if(p[i].a>=p[i].c){
						if(a1<=n/2-1){
							a1++;
							ans1+=p[i].a;
						}else{
							a3++;
							ans1+=p[i].c;
						}
					}else{
						if(a3<=n/2-1){
							a3++;
							ans1+=p[i].c;
						}else{
							a1++;
							ans1+=p[i].a;
						}
					}
				}
			}
			else if(p[i].c>=p[i].a&&p[i].c>=p[i].b){
				if(a3<=n/2-1){
					a3++;
					ans1+=p[i].c;
				}else{
					if(p[i].a>=p[i].b){
						if(a1<=n/2-1){
							a1++;
							ans1+=p[i].a;
						}else{
							a2++;
							ans1+=p[i].b;
						}
					}else{
						if(a2<=n/2-1){
							a2++;
							ans1+=p[i].b;
						}else{
							a1++;
							ans1+=p[i].a;
						}
					}
				}
			}
		}
		int ans2=0;
		a1=0,a2=0,a3=0;
		sort(p+1,p+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
				if(a1<=n/2-1){
					a1++;
					ans2+=p[i].a;
				}else{
					if(p[i].b>=p[i].c){
						if(a2<=n/2-1){
							a2++;
							ans2+=p[i].b;
						}else{
							a3++;
							ans2+=p[i].c;
						}
					}else{
						if(a3<=n/2-1){
							a3++;
							ans2+=p[i].c;
						}else{
							a2++;
							ans2+=p[i].b;
						}
					}
				}
			}
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c){
				if(a2<=n/2-1){
					a2++;
					ans2+=p[i].b;
				}else{
					if(p[i].a>=p[i].c){
						if(a1<=n/2-1){
							a1++;
							ans2+=p[i].a;
						}else{
							a3++;
							ans2+=p[i].c;
						}
					}else{
						if(a3<=n/2-1){
							a3++;
							ans2+=p[i].c;
						}else{
							a1++;
							ans2+=p[i].a;
						}
					}
				}
			}
			else if(p[i].c>=p[i].a&&p[i].c>=p[i].b){
				if(a3<=n/2-1){
					a3++;
					ans2+=p[i].c;
				}else{
					if(p[i].a>=p[i].b){
						if(a1<=n/2-1){
							a1++;
							ans2+=p[i].a;
						}else{
							a2++;
							ans2+=p[i].b;
						}
					}else{
						if(a2<=n/2-1){
							a2++;
							ans2+=p[i].b;
						}else{
							a1++;
							ans2+=p[i].a;
						}
					}
				}
			}
		}
		cout<<max(ans1,ans2)<<"\n";
	}
	return 0;
}
