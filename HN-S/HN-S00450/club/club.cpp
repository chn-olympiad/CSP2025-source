#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long T,aa,b,c;
struct node{
	int a,b,c,s;
}a[100005];
bool cmp(node a,node b){
	if(a.s>b.s){
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		aa=0;
		b=0;
		c=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].s=min(a[i].a-a[i].b,a[i].a-a[i].c);
			}
			if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].s=min(a[i].b-a[i].a,a[i].b-a[i].c);
			}
			if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				a[i].s=min(a[i].c-a[i].b,a[i].c-a[i].a);
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(aa<n/2){
				if(b<n/2){
					if(c<n/2){
						if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
							aa++;
							ans+=a[i].a;
						}
						else if(a[i].b>=a[i].c){
							b++;
							ans+=a[i].b;
						}
						else{
							c++;
							ans+=a[i].c;
						}
					}
					else{
						if(a[i].a>=a[i].b){
							aa++;
							ans+=a[i].a;
						}
						else{
							b++;
							ans+=a[i].b;
						}
					}
				}
				else{
					if(a[i].a>=a[i].c){
						aa++;
						ans+=a[i].a;
					}
					else{
						c++;
						ans+=a[i].c;
					}
				}
			}	
			else{
				if(a[i].b>=a[i].c){
					b++;
					ans+=a[i].b;
				}
				else{
					c++;
					ans+=a[i].c;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

