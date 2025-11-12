#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c,ans,maxn,f[130000];
struct as{
	int fi,se,th;
}s[130000];
void dfs(int x,int sum){
	x+=1;
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(a<n/2){
		a+=1;
		sum+=s[x].fi;
		dfs(x,sum);
		a-=1;
		sum-=s[x].fi;
	}
	if(b<n/2){
		b+=1;
		sum+=s[x].se;
		dfs(x,sum);
		b-=1;
		sum-=s[x].se;
	}
	if(c<n/2){
		c+=1;
		sum+=s[x].th;
		dfs(x,sum);
		c-=1;
		sum-=s[x].th;
	}
}
bool cmp(as x,as y){
	return x.fi>y.fi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=a=b=c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].fi>>s[i].se>>s[i].th;
			if(s[i].se==0)
				b+=1;
			if(s[i].th==0)
				c+=1;
		}
		if(b==n && c==n){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=s[i].fi;
			cout<<ans<<endl;
		}
		else{
			b=c=0;
			dfs(0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
//bool cmp(as x,as y){
//	int xx=max(x.fi,max(x.se,x.th)),yy=max(y.fi,max(y.se,y.th));/*
//	if(xx==yy){
//		if(x.fi==xx && y.fi==yy){
//			int xxx=max(x.se,x.th),yyy=max(y.se,y.th);
//			if(xxx==yyy){
//				
//			}
//		}
//		else if(x.se==xx && y.se==yy){
//			
//		}
//		else if(x.th==xx && y.th==yy){
//			
//		}
//		else{
//			return 
//		}
//	}*/
//	return xx>yy;
//}
/*sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			maxn=max(s[i].fi,max(s[i].se,s[i].th));
			if(maxn==s[i].fi){
				if(a<n/2){
					a+=1;
					aa+=s[i].fi;
					s[i].gs=1;
				}
				else{
					for(int j=1;j<i;j++){
						if(s[j].gs==1 && s[j].fi<s[i].fi){
							s[i].gs=1;
							s[j].gs=0;
							
							swap(s[i],s[j]);
						}
					}
				}
			}
			else if(maxn==s[i].se){
				if(b<n/2){
					b+=1;
					bb+=s[i].se;
					s[i].gs=2;
				}
				else{
					if(maxn==s[i].fi){
						a+=1;
						aa+=s[i].fi;
					}
					else{
						c+=1;
						cc+=s[i].th;
					}
				}
			}
			else{
				if(c<n/2){
					c+=1;
					cc+=s[i].th;
					s[i].gs=3;
				}
				else{
					if(maxn==)
				}
			}
		}*/
