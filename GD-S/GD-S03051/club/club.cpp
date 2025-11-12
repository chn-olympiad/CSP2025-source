#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,z,i,a[100005],b[100005],c[100005];
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(m=x=y=z=i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])x++;
			if(b[i]>a[i]&&b[i]>c[i])y++;
			if(c[i]>a[i]&&c[i]>b[i])z++;
			m+=max({a[i],b[i],c[i]});
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<m<<'\n';
			continue;
		}
		while(q.size())q.pop();
		if(x>n/2){
			for(i=0;i<n;i++)if(a[i]>b[i]&&a[i]>c[i])q.push(a[i]-max(b[i],c[i]));
			while(x>n/2){
				m-=q.top();
				q.pop();
				x--;
			}
		}
		if(y>n/2){
			for(i=0;i<n;i++)if(b[i]>a[i]&&b[i]>c[i])q.push(b[i]-max(a[i],c[i]));
			while(y>n/2){
				m-=q.top();
				q.pop();
				y--;
			}
		}
		if(z>n/2){
			for(i=0;i<n;i++)if(c[i]>a[i]&&c[i]>b[i])q.push(c[i]-max(a[i],b[i]));
			while(z>n/2){
				m-=q.top();
				q.pop();
				z--;
			}
		}
		cout<<m<<'\n';
	}
	return 0;
}
