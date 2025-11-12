#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a,b,c;
}st[500005];
long long amp(s a,s b){
	if(max(a.a,max(a.b,a.c))==max(b.a,max(b.b,b.c))){
		if(min(max(a.a,min(a.b,a.c)),max(a.b,min(a.a,a.c)))==min(max(b.a,min(b.b,b.c)),max(b.b,min(b.a,b.c)))){
			return min(a.a,min(a.b,a.c))>min(b.a,min(b.b,b.c));
		}
		return min(max(a.a,min(a.b,a.c)),max(a.b,min(a.a,a.c)))>min(max(b.a,min(b.b,b.c)),max(b.b,min(b.a,b.c)));
	}
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
long long t,n,x,y,z,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		x=0,y=0,z=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
		}
		sort(st+1,st+n+1,amp);
		for(int i=1;i<=n;i++){
			bool f=0;
/*			if(st[i].a>st[i].b&&st[i].a>st[i].c&&st[i+1].a>st[i+1].b&&st[i+1].a>st[i+1].c){
				if(st[i].b<st[i].a&&st[i].b>st[i].c&&st[i].b+st[i+1].a>st[i].a&&y+1<=n/2){
					y++;
					ans+=st[i].b;
					f=1;
				}else if(st[i].c<st[i].a&&st[i].c>st[i].b&&st[i].c+st[i+1].a>st[i].a&&z+1<=n/2){
					z++;
					ans+=st[i].c;
					f=1;
				}
			}
			if(st[i].c>st[i].b&&st[i].c>st[i].a&&st[i+1].c>st[i+1].b&&st[i+1].c>st[i+1].a){
				if(st[i].b<st[i].c&&st[i].b>st[i].a&&st[i].b+st[i+1].c>st[i].c&&y+1<=n/2){
					y++;
					ans+=st[i].b;
					f=1;
				}else if(st[i].a<st[i].c&&st[i].a>st[i].b&&st[i].a+st[i+1].c>st[i].c&&x+1<=n/2){
					x++;
					ans+=st[i].a;
					f=1;
				}
			}
			if(st[i].b>st[i].a&&st[i].b>st[i].c&&st[i+1].b>st[i+1].a&&st[i+1].b>st[i+1].c){
				if(st[i].a<st[i].b&&st[i].a>st[i].c&&st[i].a+st[i+1].b>st[i].b&&y+1<=n/2){
					x++;
					ans+=st[i].a;
					f=1;
				}else if(st[i].c<st[i].b&&st[i].c>st[i].a&&st[i].c+st[i+1].b>st[i].b&&z+1<=n/2){
					z++;
					ans+=st[i].c;
					f=1;
				}
			}*/
			if(st[i].a>st[i].b&&st[i].a>st[i].c&&x+1<=n/2/**/&&!f){
				x++;
				ans+=st[i].a;
				f=1;
			}else if(st[i].b>st[i].c&&y+1<=n/2){
				y++;
				ans+=st[i].b;
				f=1;
			}else if(z+1<=n/2){
				z++;
				ans+=st[i].c;
				f=1;
			}
			if(st[i].b>st[i].a&&st[i].b>st[i].c&&y+1<=n/2/**/&&!f){
				y++;
				ans+=st[i].b;
				f=1;
			}else if(st[i].a>st[i].c&&x+1<=n/2&&!f){
				x++;
				ans+=st[i].a;
				f=1;
			}else if(!f&&z+1<=n/2){
				z++;
				ans+=st[i].c;
				f=1;
			}
			if(st[i].c>st[i].a&&st[i].c>st[i].b&&z+1<=n/2/**/&&!f){
				z++;
				ans+=st[i].c;
			}else if(st[i].a>st[i].b&&x+1<=n/2&&!f){
				x++;
				ans+=st[i].a;
			}else if(!f&&y+1<=n/2){
				y++;
				ans+=st[i].b;
			}
//			cout<<st[i].a<<" "<<st[i].b<<" "<<st[i].c<<":"<<x<<" "<<y<<" "<<z<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
//Ren5Jie4Di4Ling5%
