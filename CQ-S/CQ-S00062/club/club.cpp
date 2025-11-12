#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b,c,m;
};
int cmp(S s1,S s2){
	if(s1.a==s2.a){
		if(s1.b==s2.b){
			return s1.c>s2.c;
		}
		return s1.b>s2.b;
	}
	return s1.a>s2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0,w=0,x=0,y=0,z=0;
		cin>>n;
		S s[n];
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int x1=s[i].a,y1=s[i].b,z1=s[i].c;
			s[i].a=max(x1,max(y1,z1));
			s[i].c=min(x1,min(z1,y1));
			s[i].b=x1+y1+z1-s[i].a-s[i].c;
			if(s[i].a==x1){
				s[i].m=1;
			}
			if(s[i].a==y1){
				s[i].m=2;
			}
			if(s[i].a==z1){
				s[i].m=3;
			}
		}
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++){
			if(s[i].m==1){
				if(x>=n/2){
					ans+=s[i].b;
				}
				else{
					ans+=s[i].a; 
					x++;
				}
			}
			if(s[i].m==2){
				if(y>=n/2){
					ans+=s[i].b;
				}
				else{
					ans+=s[i].a;
					y++;
				}
			}
			if(s[i].m==3){
				if(z>=n/2){
					ans+=s[i].b;
				}
				else{
					ans+=s[i].a;
					z++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
