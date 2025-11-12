#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct xx{
	int a,b,c;
	int d;
}q[200002];
int dp[200002][3];
int rs[200002][3];
int cc1(xx x,xx y){
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
int cc2(xx x,xx y){
	if(x.b==y.b) return x.c>y.c;
	return x.b>y.b;
}
int cc3(xx x,xx y){
	return x.c>y.c;
}
int cc4(xx x,xx y){
	return x.d>y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n;
long long s=0,ss=0,sss=0;
		bool o=0,u=0,e=0;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			if(q[i].a!=0){
				e=1;
			}
			if(q[i].b!=0){
				o=1;
			}
			if(q[i].c!=0){
				u=1;
			}
		}
		if(o==0&&u==0&&e==0){
			cout<<0;continue;
		}else
		if(o==0&&u==0){
			sort(q+1,q+n+1,cc1);
			for(int k=1;k<=n/2;k++){
				s+=q[k].a;
			}
			cout<<s<<endl;
			s=0;
			continue;
		}
		else if(e==0&&u==0){
			sort(q+1,q+n+1,cc2);
			for(int k=1;k<=n/2;k++){
				s+=q[k].b;
			}
			cout<<s<<endl;
			s=0;
			continue;
		}else if(e==0&&o==0){
			sort(q+1,q+n+1,cc3);
			for(int k=1;k<=n/2;k++){
				s+=q[k].c;
			}
			cout<<s<<endl;
			s=0;
			continue;
		}else if(u==0){
			for(int i=1;i<=n;i++){
				q[i].d==abs(q[i].a-q[i].b);
			}
			sort(q+1,q+n+1,cc4);
			bool t1=0,t2=0;
			long long uuu=0;
			for(int i=1;i<=n;i++){
				if(t1==n/2){
					uuu+=q[i].b;continue;
				}if(t2==n/2){
					uuu+=q[i].a;continue;
				}
				if(q[i].a>q[i].b){
					uuu+=q[i].a;
					t1++;
				}else{
					uuu+=q[i].b;
					t2++;
				}
			}
			cout<<uuu<<endl;
			continue;
		}else if(o==0){
			for(int i=1;i<=n;i++){
				q[i].d==abs(q[i].a-q[i].c);
			}
			sort(q+1,q+n+1,cc4);
			bool t1=0,t2=0;
			long long uuu=0;
			for(int i=1;i<=n;i++){
				if(t1==n/2){
					uuu+=q[i].c;continue;
				}if(t2==n/2){
					uuu+=q[i].a;continue;
				}
				if(q[i].a>q[i].c){
					uuu+=q[i].a;
					t1++;
				}else{
					uuu+=q[i].c;
					t2++;
				}
			}
			cout<<uuu<<endl;
			continue;
		}else if(e==0){
			for(int i=1;i<=n;i++){
				q[i].d==abs(q[i].b-q[i].c);
			}
			sort(q+1,q+n+1,cc4);
			bool t1=0,t2=0;
			long long uuu=0;
			for(int i=1;i<=n;i++){
				if(t1==n/2){
					uuu+=q[i].c;continue;
				}if(t2==n/2){
					uuu+=q[i].b;continue;
				}
				if(q[i].b>q[i].c){
					uuu+=q[i].b;
					t1++;
				}else{
					uuu+=q[i].c;
					t2++;
				}
			}
			cout<<uuu<<endl;
			continue;
		}else{
			sort(q+1,q+n+1,cc1);
			int b2=0;int c3=0,a1=0;
			for(int i=1;i<=n;i++){
				if(q[i].a>=q[i].b&&q[i].a>=q[i].c){
					if(a1<n/2) {
						s+=q[i].a;a1++;	
					}else{
						if(q[i].b>=q[i].c){
							if(b2<n/2){
							s+=q[i].b;b2++;
							}else{
								s+=q[i].c;c3++;
							}
						}else{
							if(c3<n/2){
								s+=q[i].c;c3++;
							}else{
								s+=q[i].b;b2++;
							}
						}
					}
				}else if(q[i].b>=q[i].a&&q[i].b>=q[i].c){
					if(b2<n/2) {
						s+=q[i].b;b2++;	
					}else{
						if(q[i].a>=q[i].c){
							if(a1<n/2){
							s+=q[i].a;a1++;
							}else{
								s+=q[i].c;c3++;
							}
						}else{
							if(c3<n/2){
								s+=q[i].c;c3++;
							}else{
								s+=q[i].a;a1++;
							}
						}
					}
				}else if(q[i].c>=q[i].b&&q[i].c>=q[i].a){
					if(c3<n/2) {
						s+=q[i].c;c3++;	
					}else{
						if(q[i].b>=q[i].a){
							if(b2<n/2){
							s+=q[i].b;b2++;
							}else{
								s+=q[i].a;a1++;
							}
						}else{
							if(a1<n/2){
								s+=q[i].a;a1++;
							}else{
								s+=q[i].b;b2++;
							}
						}
					}
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
