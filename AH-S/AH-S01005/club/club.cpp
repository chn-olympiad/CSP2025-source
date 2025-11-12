#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
int t,n,p[4],ans;
struct Node{
	ll id,s;
}a[N][4];
struct Node2{
	ll maxn1,maxn2,maxn3;
	ll id1,id2,id3;
}m[N];
bool cmp1(Node x,Node y){
	return x.s>y.s;
}
bool cmp2(Node2 x,Node2 y){
	if(x.maxn1!=y.maxn1) return x.maxn1>y.maxn1;
	if(x.maxn2!=y.maxn2) return x.maxn2>y.maxn2;
	return x.maxn3>y.maxn3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		memset(m,0,sizeof m);
		memset(a,0,sizeof a);
		memset(p,0,sizeof p);
	    cin>>n;
	    for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			    cin>>a[i][j].s;
			    a[i][j].id=j;
		    }
		    sort(a[i]+1,a[i]+4,cmp1);
		    m[i].maxn1=a[i][1].s;m[i].maxn2=a[i][2].s;m[i].maxn3=a[i][3].s;
		    m[i].id1=a[i][1].id;m[i].id2=a[i][2].id;m[i].id3=a[i][3].id;
		    
		}
		sort(m+1,m+1+n,cmp2);
		for(int i=1;i<=n;i++){
			//cout<<m[i].maxn1<<" "<<m[i].maxn2<<" "<<m[i].maxn3<<endl;
			//cout<<m[i].id1<<" "<<m[i].id2<<" "<<m[i].id3<<endl;
			if(p[m[i].id1]==n/2-1){
				//cout<<"hi\n";
				if(p[m[i+1].id2]<=n/2&&p[m[i].id2]<=n/2){
				   ll x=m[i].maxn1+m[i+1].maxn2,y=m[i+1].maxn1+m[i].maxn2;
				   if(x<=y){
					    ans+=m[i].maxn2;
						p[m[i].id2]++;
				   }else{
						ans+=m[i].maxn1;
						p[m[i].id1]++;
				   }
				 }else if(p[m[i+1].id2]>=n/2&&p[m[i].id2]<=n/2)	 {
				       ll x=m[i].maxn1,y=m[i+1].maxn1+m[i].maxn2;
				       if(x<=y){
					    ans+=m[i].maxn2;
						p[m[i].id2]++;
				       }else{
						  ans+=m[i].maxn1;
						  p[m[i].id1]++;  
					   }
				}
			}else if(p[m[i].id1]<n/2-1){
			   ans+=m[i].maxn1;
			   p[m[i].id1]++;
			}
		}
		cout<<ans<<endl;
		 ans=0;
	}
    return 0;
}
