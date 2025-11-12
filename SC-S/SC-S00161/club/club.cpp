#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
	
};
node a[10050];
node b[10050];
node c[10050];
int n;
int ans,shu;
iny af,bf,cf;
int s[10050];
bool cmp1(node x,node y){
	return x.num>y.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
			
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp1);
		while(n--){
			int fl=0;
			if(a[af]==max(a[af],max(b[bf],c[cf]))){
				if(s[af]==0){
					s[af]=1;
					fl=1;
				    ans+=a[af];
				    
				}
				else a[af]=-1;
				
				if(b[bf]==max(a[af],max(b[bf],c[cf])) and fl==0){
				if(s[bf]==0){
					s[bf]=1;
					fl=1;
				    ans+=b[af];
				    
				}
				else b[bf]=-1;
			}
			
            if(c[cf]==max(a[af],max(b[bf],c[cf])) and fl==0){
				if(s[cf]==0 ){
					s[cf]=1;
					fl=1;
				    ans+=c[cf];
				    
				}
				else c[cf]=-1;
			}
			
			
			}
			if(b[bf]==max(a[af],max(b[bf],c[cf]))){
				if(s[bf]==0){
					s[af]=1;
					fl=1;
				    ans+=a[af];
				    
				}
				else a[af]=-1;
				
				if(b[bf]==max(a[af],max(b[bf],c[cf])) and fl==1){
				if(s[bf]==0){
					s[bf]=1;
					fl=1;
				    ans+=b[af];
				    
				}
				else b[bf]=-1;
			}
			
            if(c[cf]==max(a[af],max(b[bf],c[cf])) and fl==1){
				if(s[cf]==0 ){
					s[cf]=1;
					fl=1;
				    ans+=c[cf];
				    
				}
				else c[cf]=-1;
			}
			
			
			}
			if(fl==0) n++;
		}
		
		
	}
	return 0;
} 