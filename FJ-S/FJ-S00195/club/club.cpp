#include<bits/stdc++.h>
using namespace std;
struct node{
	int ch,a,b,c;
};
bool operator<(node m,node n){
	return m.ch>n.ch;
}
int getch(int a,int b,int c){
	if(a>=b&&b>=c) return a-b;
	if(a>=c&&c>=b) return a-c;
	if(b>=a&&a>=c) return b-a;
	if(b>=c&&c>=a) return b-c;
	if(c>=a&&a>=b) return c-a;
	if(c>=b&&b>=a) return c-b;
}
int maxx(int a,int b,int c){
    return max(a,max(b,c));	
} 
priority_queue<node> pq1,pq2,pq3;
int t,n,x,y,z,cnt1,cnt2,cnt3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		cnt1=cnt2=cnt3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
		    scanf("%d%d%d",&x,&y,&z);
		    node no={getch(x,y,z),x,y,z};
		    int ma=maxx(x,y,z);
		    if(ma==x){
		    	if(cnt1<n/2){
		    		pq1.push(no);
		    		cnt1++;
		    		ans+=no.a;
				}else{
					node nn=pq1.top();
					if(nn.ch<no.ch){
						pq1.pop();
						pq1.push(no);
						ans+=no.a;
						ans-=nn.ch;
						if(nn.b>nn.c){
							pq2.push(nn);
							cnt2++;
						}else{
							pq3.push(nn);
							cnt3++;
						}
					}else{
						if(no.b>no.c){
							pq2.push(no);
							cnt2++;
							ans+=no.b;
						}else{
							pq3.push(no);
							cnt3++;	
							ans+=no.c;
						}
					}
				}
			}
		    else if(ma==y){
		    	if(cnt2<n/2){
		    		pq2.push(no);
		    		cnt2++;
		    		ans+=no.b;
				}else{
					node nn=pq2.top();
					if(nn.ch<no.ch){
						pq2.pop();
						pq2.push(no);
						ans+=no.b;
						ans-=nn.ch;
						if(nn.a>nn.c){
							pq1.push(nn);
							cnt1++;
						}else{
							pq3.push(nn);
							cnt3++;
						}
					}else{
						if(no.a>no.c){
							pq1.push(no);
							cnt1++;
							ans+=no.a;
						}else{
							pq3.push(no);
							cnt3++;	
							ans+=no.c;
						}
					}
				}
			}
		    else if(ma==z){
		    	if(cnt3<n/2){
		    		pq3.push(no);
		    		cnt3++;
		    		ans+=no.c;
				}else{
					node nn=pq3.top();
					if(nn.ch<no.ch){
						pq3.pop();
						pq3.push(no);
						ans+=no.c;
						ans-=nn.ch;
						if(nn.a>nn.b){
							pq1.push(nn);
							cnt1++;
						}else{
							pq2.push(nn);
							cnt2++;
						}
					}else{
						if(no.a>no.b){
							pq1.push(no);
							cnt1++;
							ans+=no.a;
						}else{
							pq2.push(no);
							cnt2++;	
							ans+=no.b;
						}
					}
				}
			}
			
		} 
		printf("%d\n",ans);
		while(!pq1.empty()) pq1.pop();
		while(!pq2.empty()) pq2.pop();
		while(!pq3.empty()) pq3.pop();
	}
	return 0;
}
