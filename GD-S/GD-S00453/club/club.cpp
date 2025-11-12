#include<bits/stdc++.h>
using namespace std;
long long t,n,e,e1,o;
struct node{
	long long a;
};
node a[100005],b[100005],c[100005],d[100005];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		long long a1=0,b1=0,c1=0;
		for(int j=1;j<=n;j++){
			cin >> a[j].a>>b[j].a>>c[j].a;
			if(a[j].a==0||b[j].a==0||c[j].a==0){
				o++;
			}
		}
		if(o>=2*n){
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			a1=0,b1=0,c1=0;
			for(int j=1;j<=n;j++){
				long long f1=max(max(a[j].a,b[j].a),c[j].a);
				if(f1==a[j].a){
					if(a1<n/2){
						e1+=f1;
						a1++;
					}else{
						if(max(b[j].a,c[j].a)==b[j].a){
							if(b1<n/2){
								e1+=b[j].a;
								b1++;
							}
						}
						else{
							if(c1<n/2){
								e1+=c[j].a;
								c1++;
							}
						}
					}
				}
				if(f1==b[j].a){
					if(b1<n/2){
						e1+=f1;
						b1++;
					}else{
						if(max(a[j].a,c[j].a)==a[j].a){
							if(a1<n/2){
								e1+=a[j].a;
								a1++;
							}
						}
						else{
							if(c1<n/2){
								e1+=c[j].a;
								c1++;
							}
						}
					}
				}
				if(f1==c[j].a){
					if(c1<n/2){
						e1+=f1;
						c1++;
					}else{
						if(max(b[j].a,a[j].a)==b[j].a){
							if(b1<n/2){
								e1+=b[j].a;
								b1++;
							}
						}
						else{
							if(a1<n/2){
								e1+=a[j].a;
								a1++;
							}
						}
					}
				}
				continue;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				long long f=max(max(a[j].a,b[j].a),c[j].a);
				if(f==a[j].a){
					if(a1<n/2){
						e+=f;
						a1++;
					}else{
						if(max(b[j].a,c[j].a)==b[j].a){
							if(b1<n/2){
								e+=b[j].a;
								b1++;
							}
						}
						else{
							if(c1<n/2){
								e+=c[j].a;
								c1++;
							}
						}
					}
					continue;
				}
				if(f==b[j].a){
					if(b1<n/2){
						e+=f;
						b1++;
					}else{
						if(max(a[j].a,c[j].a)==a[j].a){
							if(a1<n/2){
								e+=a[j].a;
								a1++;
							}
						}
						else{
							if(c1<n/2){
								e+=c[j].a;
								c1++;
							}
						}
					}
					continue;
				}
				if(f==c[j].a){
					if(c1<n/2){
						e+=f;
						c1++;
					}else{
						if(max(b[j].a,a[j].a)==b[j].a){
							if(b1<n/2){
								e+=b[j].a;
								b1++;
							}
						}
						else{
							if(a1<n/2){
								e+=a[j].a;
								a1++;
							}
						}
					}
					continue;
				}
			}
			
		}
			
		cout <<max(e,e1)<<endl;
		e=0,e1=0,o=0;
	}
} 
