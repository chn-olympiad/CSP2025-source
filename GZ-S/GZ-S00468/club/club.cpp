//GZ-S00468 贵阳市白云区华师一学校 陈思成 
#include<bits/stdc++.h>
using namespace std;
struct str{
	int a,b,c,maxx,midd,minn;
}m[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,ans=0,s[3];
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>m[j].a>>m[j].b>>m[j].c;
			m[j].maxx=max(max(m[j].a,m[j].b),m[j].c);
			m[j].minn=min((m[j].a,m[j].b),m[j].c);
			if(m[j].a!=m[j].maxx&&m[j].a!=m[j].minn) m[j].midd=m[j].a;
			if(m[j].b!=m[j].maxx&&m[j].b!=m[j].minn) m[j].midd=m[j].b;
			if(m[j].c!=m[j].maxx&&m[j].c!=m[j].minn) m[j].midd=m[j].c;
			ans+=m[j].maxx;
			if(m[j].maxx==m[j].a) s[1]++;
			else if(m[j].maxx==m[j].b) s[2]++;
			else s[3]++;
		}
		for(int o=1;o<=3;o++){
			if(s[o]>n/2){
				int ansm=-1;
				while(s[o]>n/2){
					for(int v=1;v<=n;v++){
						ans-=m[v].maxx;
						ans+=m[v].midd;
						if(ans>ansm) ansm=v;
						ans+=m[v].maxx;
						ans-=m[v].midd;
					}
					ans-=m[ansm].maxx;
					ans+=m[ansm].midd;
					s[o]--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
