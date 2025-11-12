#include<bits/stdc++.h>
using namespace std;
long long a[100005][4];
priority_queue<int,vector<int>,greater<int> > b;
priority_queue<int,vector<int>,greater<int> > c;
priority_queue<int,vector<int>,greater<int> > d;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int m=0,x=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>m){
					m=a[i][j];
					x=j;
				}
			}
			if(x==1){
				if(b.size()<(n/2)){
					b.push(m);
					ans+=m;
				}
				else{
					if(m>b.top()){
						ans-=b.top();
						for(int i=1;i<=n;i++){
							if(a[i][1]==b.top()){
								if(c.size()<(n/2)){
									c.push(a[i][2]);
									ans+=a[i][2];
								}
								else if(a[i][2]>c.top()){
									ans-=c.top();
									c.pop();
									c.push(a[i][2]);
									ans+=a[i][2];
								}
							}
						} 
						b.pop();
						b.push(m);
						ans+=m;
					}
				}
			}
			if(x==2){
				if(c.size()<(n/2)){
					c.push(m);
					ans+=m;
				}
				else if(m>c.top()){
					ans-=c.top();
					for(int i=1;i<=n;i++){
						if(a[i][2]==c.top()){
							if(b.size()<(n/2)){
								b.push(a[i][1]);
								ans+=a[i][1];
							}
							else if(a[i][2]>b.top()){
								ans-=b.top();
								b.pop();
								b.push(a[i][2]);
								ans+=a[i][2];
							}
						}
					} 
					c.pop();
					c.push(m);
					ans+=m;
				}
			}
			if(x==3){
				if(d.size()<(n/2)){
					d.push(m);
					ans+=m;
				}
				else if(m>b.top()){
					ans-=d.top();
					d.pop();
					d.push(m);
					ans+=m;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
