#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int a,b,c,Ca,Cb;
	int ra,rb,rc;
	friend bool operator < (node A,node B){return A.Ca>B.Ca||(A.Ca==B.Ca && A.Cb>B.Cb);}
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
 	int A=0,B=0,C=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].ra=1;
				if(a[i].b>=a[i].c){
					a[i].rb=2;a[i].rc=3;
					a[i].Ca=a[i].a-a[i].b;
					a[i].Cb=a[i].a-a[i].c;
				}else{
					a[i].rb=3;a[i].rc=2;
					a[i].Ca=a[i].a-a[i].c;
					a[i].Cb=a[i].a-a[i].b;
				}
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].ra=2;
				if(a[i].a>=a[i].c){
					a[i].rb=1;a[i].rc=3;
					a[i].Ca=a[i].b-a[i].a;
					a[i].Cb=a[i].b-a[i].c;
				}else{
					a[i].rb=3;a[i].rc=1;
					a[i].Ca=a[i].b-a[i].c;
					a[i].Cb=a[i].b-a[i].a;
				}
			}else{
				a[i].ra=3;
				if(a[i].a>=a[i].b){
					a[i].rb=1;a[i].rc=2;
					a[i].Ca=a[i].c-a[i].a;
					a[i].Cb=a[i].c-a[i].b;
				}else{
					a[i].rb=2;a[i].rc=1;
					a[i].Ca=a[i].c-a[i].b;
					a[i].Cb=a[i].c-a[i].a;
				}
			}
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			switch(a[i].ra){
				case 1:ans+=a[i].a;break;
				case 2:ans+=a[i].b;break;
				case 3:ans+=a[i].c;break;
			}
			if(a[i].ra==1){
				if(A<n/2)A++;
				else{
					if(a[i].rb==2){
						if(B<n/2){
							B++;
							ans-=a[i].Ca;
						}else{
							C++;
							ans-=a[i].Cb;
						}
					}else{
						if(C<n/2){
							C++;
							ans-=a[i].Ca;
						}else{
							B++;
							ans-=a[i].Cb;
						}
					}
				}
			}else if(a[i].ra==2){
				if(B<n/2)B++;
				else{
					if(a[i].rb==1){
						if(A<n/2){
							A++;
							ans-=a[i].Ca;
						}else{
							C++;
							ans-=a[i].Cb;
						}
					}else{
						if(C<n/2){
							C++;
							ans-=a[i].Ca;
						}else{
							A++;
							ans-=a[i].Cb;
						}
					}
				}
			}else{
				if(C<n/2)C++;
				else{
					if(a[i].rb==1){
						if(A<n/2){
							A++;
							ans-=a[i].Ca;
						}else{
							B++;
							ans-=a[i].Cb;
						}
					}else{
						if(B<n/2){
							B++;
							ans-=a[i].Ca;
						}else{
							A++;
							ans-=a[i].Cb;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
