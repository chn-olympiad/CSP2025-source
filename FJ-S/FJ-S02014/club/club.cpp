#include<bits/stdc++.h>
using namespace std;
int t,n;
struct mode{
	int a;
	int b;
	int c;
	int d;
}s[100001];
int cmp(const mode &c,const mode &d){
	if(c.d>d.d){
		return c.d>d.d;
	}
	else if(c.d==d.d){
		return (c.a-c.b)<(d.a-d.b);
	}
	return c.d>d.d;
}
int ccp(const mode &c,const mode &d){
		if(c.d>d.d){
		return c.d>d.d;
	}
	else if(c.d==d.d){
		return (c.a-c.b)>(d.a-d.b);
	}
	return c.d>d.d;
}
int cnp(const mode &c,const mode &d){
	
		return (c.a-c.b)<(d.a-d.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a[4];
		int sa=0,sb=0,sc=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[1]);
			scanf("%d",&a[2]);
			scanf("%d",&a[3]);
			if(a[1]>=a[2]&&a[1]>=a[3]){
				s[j].a=a[1];
				s[j].d=1;
				sa++;
				if(a[2]>=a[3]){
					s[j].b=a[2];
					s[j].c=a[3];
				}
				else{
					s[j].b=a[3];
					s[j].c=a[2];
				}
			}
			else if(a[2]>=a[1]&&a[2]>=a[3]){
				s[j].a=a[2];
				s[j].d=2;
				sb++;
				if(a[1]>=a[3]){
					s[j].b=a[1];
					s[j].c=a[3];
				}
				else{
					s[j].b=a[3];
					s[j].c=a[1];
				}
			}else if(a[3]>=a[1]&&a[3]>=a[2]){
				s[j].a=a[3];
				s[j].d=3;
				sc++;
				if(a[2]>=a[1]){
					s[j].b=a[2];
					s[j].c=a[1];
				}
				else{
					s[j].b=a[1];
					s[j].c=a[2];
				}
			}
		}
		if(sa<=n/2) sort(s+1,s+1+n,cmp);

		int ans=0;
		if(sc>n/2){
			ans=0;
			sort(s+sc+1,s+1+n,cnp);
			for(int j=1;j<=n;j++){
				if(sc>n/2){
					ans+=s[j].b;
					sc--;
				}
				else{
					ans+=s[j].a;
				}
			}
		}
		else if(sb>n/2){
			ans=0;
			for(int j=sc+1;j<=sc+sb;j++){
				s[j].d+=2;
			}
			sort(s+1,s+1+n,cmp);
			sort(s+sb+1,s+1+n,cnp);
			for(int j=1;j<=n;j++){
				if(sb>n/2){
					ans+=s[j].b;
					sb--;
				}
				else{
					ans+=s[j].a;
				}
			}
		}
		else if(sa>n/2){
	
			ans=0;
			sort(s+1,s+1+n,ccp);
			sort(s+1,s+sb+sc+1,cnp);
			for(int j=n;j>=1;j--){
				if(sa>n/2){
					ans+=s[j].b;
					sa--;
				}
				else{
					ans+=s[j].a;
				}
			}
		}
		else{
			
			for(int j=1;j<=n;j++){
				ans+=s[j].a;
			}	
		}
			printf("%d\n",ans);
		
	}
	return 0;

}
