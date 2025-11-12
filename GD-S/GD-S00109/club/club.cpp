#include<bits/stdc++.h>
using namespace std;
int a[100005][3],t,n,x,y,z,f[100005],s[100005],noww,ans;
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				f[i]=max(a[i][0],max(a[i][1],a[i][2]));
				s[i]=a[i][0]+a[i][1]+a[i][2]-f[i]-min(a[i][0],min(a[i][1],a[i][2]));
			}
		}
		for(int i=1;i<=n;i++){
			noww=f[i]-s[i];
			if(f[i]==a[i][0]){
				if(x==n/2){
					if(noww<=q1.top()){
						ans+=s[i];
					}
					else{
						ans-=q1.top();
						q1.pop();
						ans+=f[i];
						q1.push(noww);
					}
				}
				else{
					ans+=f[i];
					x++;
					q1.push(noww);
				}
			}
			else if(f[i]==a[i][1]){
				if(y==n/2){
					if(noww<=q2.top()){
						ans+=s[i];
					}
					else{
						ans-=q2.top();
						q2.pop();
						ans+=f[i];
						q2.push(noww);
					}
				}
				else{
					ans+=f[i];
					y++;
					q2.push(noww);
				}
			}
			else{
				if(z==n/2){
					if(noww<=q3.top()){
						ans+=s[i];
					}
					else{
						ans-=q3.top();
						q3.pop();
						ans+=f[i];
						q3.push(noww);
					}
				}
				else{
					z++;
					ans+=f[i];
					q3.push(noww);
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		x=0;
		y=0;
		z=0;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
	}
	return 0;
} 
