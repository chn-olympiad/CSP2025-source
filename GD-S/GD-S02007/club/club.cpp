#include<bits/stdc++.h>
using namespace std;

int t,n,a[250000];
int m[250000],A=0,B=0,C=0,tot=0;
bool vis[250000];

struct r{
	int a,b,c,maxr;
}r[250000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		A=0,B=0,C=0;
		memset(vis,false,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
			//r[i].maxr=max(r[i].a,max(r[i].b,r[i].c));
			r[i].maxr=r[i].a+r[i].b+r[i].c;
			m[i]=r[i].maxr;
		}
		sort(m+1,m+n+1);
		for(int i=n;i>=1;i--){
		//	cout<<"i="<<i<<endl;
			for(int j=1;j<=n;j++){
			//	cout<<"j="<<j<<endl;
				if((!vis[j])&&m[i]==r[j].maxr){
					vis[j]=1;
					if(r[j].a>=r[j].b&&r[j].a>=r[j].c&&A<n/2){
						tot+=r[j].a;
						A++;
					//	cout<<"j="<<j<<endl;
					//	cout<<"a="<<r[j].a<<endl;
					}
					else if(r[j].b>=r[j].c&&B<n/2){
						tot+=r[j].b;
						B++;
					//	cout<<"j="<<j<<endl;
					//	cout<<"b="<<r[j].b<<endl;
					}
					else if(C<n/2){
						tot+=r[j].c;
						C++;
					//	cout<<"j="<<j<<endl;
					//	cout<<"c="<<r[j].c<<endl;
					}
				}
			}
		}
		cout<<tot<<endl;
		tot=0;
	}
	
	return 0;
} 
