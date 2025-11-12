#include<bits/stdc++.h>
using namespace std;
struct Q{
	pair<int,int> l1;
	pair<int,int> l2;
}q[10010];
int a[10010][3],b[10010][3],c[10010][3];

int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
    int t;
   // cin>>t;
   // while(t--){
		memset(q,0,sizeof(q));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n=0,m=0,x=0,y=0,z=0;
		int h1=0,h2=0,h3=0;
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x==max(x,max(y,z))){
				q[i].l1.first=x;
				q[i].l1.second=1;
				if(y==min(y,z)){
					q[i].l2.first=z;
			    	q[i].l2.second=3;
				}
				else{
					q[i].l2.first=y;
			    	q[i].l2.second=2;
				}
			}
			if(y==max(y,max(x,z))){
				q[i].l1.first=y;
				q[i].l1.second=2;
				if(x==min(x,z)){
					q[i].l2.first=z;
			    	q[i].l2.second=3;
				}
				else{
					q[i].l2.first=x;
			    	q[i].l2.second=1;
				}
			}
			if(z==max(y,max(x,z))){
				q[i].l1.first=z;
				q[i].l1.second=3;
				if(x==min(y,x)){
					q[i].l2.first=y;
			    	q[i].l2.second=2;
				}
				else{
					q[i].l2.first=x;
			    	q[i].l2.second=1;
				}
			}
		}
			
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(q[i].l1.second==1){
				cnt++;
				a[cnt][1]=q[i].l1.first;
				a[cnt][2]=i;
				h1+=q[i].l1.first;
			//	cout<<cnt<<" ";
				if(cnt>m){
					int ans=-1;
					for(int j=1;j<=cnt;j++){
						ans=max(ans,h1-q[a[j][2]].l1.first+q[a[j][2]].l2.first);
					//	cout<<q[a[j][2]].l2.first<<" ";
					}
					h1=ans;
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(q[i].l1.second==2){
				cnt++;
				b[cnt][1]=q[i].l1.first;
				b[cnt][2]=i;
				h2+=q[i].l1.first;
				if(cnt>m){
					int ans=-1;
					for(int j=1;j<=cnt;j++){
			
						ans=max(ans,h2-q[b[j][2]].l1.first+q[b[j][2]].l2.first);	
					}
					h2=ans;
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(q[i].l1.second==3){
				cnt++;
				c[cnt][1]=q[i].l1.first;
				c[cnt][2]=i;
				h3+=q[i].l1.first;
				int ans=-1;
				if(cnt>m){
					cout<<cnt<<" ";
					for(int j=1;j<=cnt;j++){
						ans=max(ans,h3-q[c[j][2]].l1.first+q[c[j][2]].l2.first);
						cout<<ans<<" ";
					}
					h3=ans;
				}
			}
		}
		int ans=0;
		ans=h1+h2+h3;
		cout<<ans;
//	}
}
