#include<bits/stdc++.h>
using namespace std;
int b[100009],c[100009],d[100009],tg[100009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int a,fi=0,se=0,th=0,ans=0;
		cin>>a;
		for(int i=1;i<=a;i++)cin>>b[i]>>c[i]>>d[i];
		for(int i=1;i<=a;i++){
			if(b[i]>d[i]&&b[i]>c[i])fi++,tg[i]=1,ans+=b[i];
			else if(d[i]<c[i])se++,tg[i]=2,ans+=c[i];
			else th++,tg[i]=3,ans+=d[i];
		}
		if(fi*2>a){
			priority_queue<int>pq;
			for(int i=1;i<=a;i++){
				if(tg[i]==1){
					pq.push(-min(b[i]-c[i],b[i]-d[i]));
				}
			}
			while(fi*2>a){
				ans=ans+pq.top();
				pq.pop();
				fi--;
			}
		}else if(se*2>a){
			priority_queue<int>pq;
			for(int i=1;i<=a;i++){
				if(tg[i]==2){
					pq.push(-min(c[i]-b[i],c[i]-d[i]));
				}
			}
			while(se*2>a){
				ans=ans+pq.top();
				pq.pop();
				se--;
			}
		}else if(th*2>a){
			priority_queue<int>pq;
			for(int i=1;i<=a;i++){
				if(tg[i]==3){
					pq.push(-min(d[i]-b[i],d[i]-c[i]));
				}
			}
			while(th*2>a){
				ans=ans+pq.top();
				pq.pop();
				th--;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
