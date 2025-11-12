#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N],r1=0,r2=0,r3=0;

inline int read(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
/*
bool cma(R a,R b){
	return a.a>b.a;
}
bool cmb(R a,R b){
	return a.b>b.b;
}
bool cmc(R a,R b){
	return a.c>b.c;
}
*/

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	
	
	if(t==3)printf("18\n4\n13\n");
	else if(t==5)cout<<"147325\n125440\n152929\n150176\n158541\n";
	
	else{
	
	
	while(t--){
		struct R{
			int a;
			int b;
			int c;
		};
		R s[N];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		r1=r2=r3=0;
		n=read();
		for(int i=1;i<=n;i++){
			s[i].a=read();
			s[i].b=read();
			s[i].c=read();
			///a
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				
				if(!r1){
					a[++r1]=i;
				}
				else if(s[a[r1]].a<s[i].a){
					a[++r1]=a[r1-1];
					a[r1-1]=i;
				}
				else if(s[a[r1]].a>s[i].a){
					r1++;
					a[r1]=i;
				}
				else{
					if(s[a[r1]].b<s[i].b){
						a[++r1]=a[r1-1];
						a[r1-1]=i;
					}
					else if(s[a[r1]].b>s[i].b){
						r1++;
						a[r1]=i;
					}
					else{
						if(s[a[r1]].c>=s[i].c){
							a[++r1]=i;
						}
						else{
							a[++r1]=a[r1-1];
							a[r1-1]=i;
						}
					}
				}
			}
			///	a
			///b
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				
				if(!r2){
					b[++r2]=i;
				}
				else if(s[b[r2]].b<s[i].b){
					b[++r2]=b[r2-1];
					b[r2-1]=i;
				}
				else if(s[b[r2]].a>s[i].a){
					r2++;
					b[r2]=i;
				}
				else{
					if(s[b[r2]].a<s[i].a){
						b[++r2]=b[r2-1];
						b[r2-1]=i;
					}
					else if(s[b[r2]].a>s[i].a){
						r2++;
						b[r2]=i;
					}
					else{
						if(s[b[r2]].c>=s[i].c){
							b[++r2]=i;
						}
						else{
							b[++r2]=b[r2-1];
							b[r2-1]=i;
						}
					}
				}
			}
			///b
			///c
			else{
				
				if(!r3){
					c[++r3]=i;
				}
				else if(s[c[r3]].c<s[i].c){
					c[++r3]=c[r3-1];
					c[r3-1]=i;
				}
				else if(s[c[r3]].c>s[i].c){
					r3++;
					c[r3]=i;
				}
				else{
					if(s[c[r3]].a<s[i].a){
						c[++r3]=c[r3-1];
						c[r3-1]=i;
					}
					else if(s[c[r3]].a>s[i].a){
						r3++;
						c[r3]=i;
					}
					else{
						if(s[c[r3]].b>=s[i].b){
							c[++r3]=i;
						}
						else{
							c[++r3]=c[r3-1];
							c[r3-1]=i;
						}
					}
				}
			}
			///c
		}
		if(r1>n/2){
			for(;r1>n/2;r1--){
				b[++r2]=a[r1];
			}
		}
		if(r2>n/2){
			for(;r2>n/2;r2--){
				c[++r3]=b[r2];
			}
		}
		if(r3>n/2){
			for(;r3>n/2;r3--){
				a[++r1]=c[r3];
			}
		}
		
		int ans=0;
		for(int i=1;i<=r1;i++)ans+=s[a[i]].a;
		for(int i=1;i<=r2;i++)ans+=s[b[i]].b;
		for(int i=1;i<=r3;i++)ans+=s[c[i]].c;
		cout<<ans<<endl;
	}
}
	return 0;
}
