#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,ans,ax,bx,cx;
bool tsa;
struct Stu{
	int a,b,c,mx;
	bool operator < (const Stu x)const{
	    return mx>x.mx;
	}
}s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ax=bx=cx=ans=0;
		tsa=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		    scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
		    if(s[i].c || s[i].b)tsa=false;
		    if((s[i].a<=s[i].b && s[i].a>=s[i].c)||(s[i].a>=s[i].b && s[i].a<=s[i].c)){
		    	ans+=s[i].a;
		    	s[i].b-=s[i].a;
		    	s[i].c-=s[i].a;
		    	s[i].a=0;
			}
			else if((s[i].a<=s[i].b && s[i].b<=s[i].c)||(s[i].c<=s[i].b && s[i].b<=s[i].a)){
		    	ans+=s[i].b;
		    	s[i].a-=s[i].b;
		    	s[i].c-=s[i].b;
		    	s[i].b=0;
			}
			else if((s[i].a<=s[i].c && s[i].c<=s[i].b)||(s[i].b<=s[i].c && s[i].c<=s[i].a)){
		    	ans+=s[i].c;
		    	s[i].a-=s[i].c;
		    	s[i].b-=s[i].c;
		    	s[i].c=0;
			}
			s[i].mx=max(max(s[i].a,s[i].b),s[i].c);
			//printf("%d %d %d\n",s[i].a,s[i].b,s[i].c);
		}
		sort(s+1,s+n+1);
		if(tsa){
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a;
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i].a>=s[i].b && s[i].a>=s[i].c){
				if(ax<n/2)ax++,ans+=s[i].a;
				else if(s[i].b>=s[i].c){
					if(bx<n/2)bx++,ans+=s[i].b;
					else cx++,ans+=s[i].c;
				}
				else if(s[i].c>=s[i].b){
					if(cx<n/2)cx++,ans+=s[i].c;
					else bx++,ans+=s[i].b;
				}
			}
			else if(s[i].b>=s[i].a && s[i].b>=s[i].c){
				if(bx<n/2)bx++,ans+=s[i].b;
				else if(s[i].a>=s[i].c){
					if(ax<n/2)ax++,ans+=s[i].a;
					else cx++,ans+=s[i].c;
				}
				else if(s[i].c>=s[i].a){
					if(cx<n/2)cx++,ans+=s[i].c;
					else ax++,ans+=s[i].a;
				}
			}
			else if(s[i].c>=s[i].a && s[i].c>=s[i].b){
				if(cx<n/2)cx++,ans+=s[i].c;
				else if(s[i].a>=s[i].b){
					if(ax<n/2)ax++,ans+=s[i].a;
					else bx++,ans+=s[i].b;
				}
				else if(s[i].b>=s[i].a){
					if(bx<n/2)bx++,ans+=s[i].b;
					else ax++,ans+=s[i].a;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
