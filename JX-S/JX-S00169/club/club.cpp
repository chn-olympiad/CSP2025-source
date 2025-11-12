#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int q,w,e,qq,ww,ee;
int t,n,cnt,cntt,cnttt;
long long ans;
struct node{
	int a,b,c;
}x[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
        if(n==2){
			long long p,o,z,q,w,e;
			p=x[1].a;
			o=x[1].b;
			z=x[1].c;
			q=x[2].a;
			w=x[2].b;
			e=x[2].c;
			ans=max(z+q,max(p+w,max(p+e,max(o+q,max(z+w,o+e)))));
			cout<<ans;
			ans=0;
			continue;
		}
        for(int i=1;i<=n;i++){
            qq=x[i].a;
            ww=x[i].b;
            ee=x[i].c;
            e=max(max(qq,ww),ee);
            if(e==x[i].b){
				e=2;
				w=max(qq,ee);
				if(qq==w) w=1;
				else w=3;
			}
            else if(e==x[i].a){
				e=1;
				w=max(ww,ee);
				if(w==ww) w=2;
				else w=3;
			}
            else{
				e=3;
				w=max(qq,ww);
				if(w==qq) w=1;
				else w=2;
			}
            if(e==1){
				if(cnt<n/2){
					cnt++;
				    ans+=x[i].a;
				}
				else{
					if(w==2){
						cntt++;
						ans+=x[i].b;
					}
					else{
						cnttt++;
						ans+=x[i].c;
					}
				}
			}
			else if(e==2){
				if(cntt<n/2){
					cntt++;
				    ans+=x[i].b;
				}
				else{
					if(w==1){
						cnt++;
						ans+=x[i].a;
					}
					else{
						cnttt++;
						ans+=x[i].c;
					}
				}
			}
			else{
				if(cnt<n/2){
					cnttt++;
				    ans+=x[i].c;
				}
				else{
					if(w==2){
						cntt++;
						ans+=x[i].b;
					}
					else{
						cnt++;
						ans+=x[i].a;
					}
				}
			}
        }
        cout<<ans;
        puts("");
        ans=0;
        cnt=0;
        cntt=0;
        cnttt=0;
    }
    return 0;
}
