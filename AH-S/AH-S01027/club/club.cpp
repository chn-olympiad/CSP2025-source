#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
	int a,b,c,atb,atc,btc,bta,cta,ctb;
	int ca,cb,cc;
	int x,y,z;
	int px[4];
}s[N];
struct ino{
	int tb,tc;
}io[N];
struct inp{
	int ta,tc;
}ip[N];
struct inq{
	int ta,tb;
}iq[N];
bool cmp1(ino m,ino n){
	int difftb=abs(m.tb-n.tb);
	int difftc=abs(m.tc-n.tc);{
		if(difftb<=difftc){
			return m.tb>n.tb;
		}else{
			return m.tc>n.tc;
		}
	}
}
bool cmp2(inp m,inp n){
	int diffta=abs(m.ta-n.ta);
	int difftc=abs(m.tc-n.tc);{
		if(diffta<=difftc){
			return m.ta>n.ta;
		}else{
			return m.tc>n.tc;
		}
	}
}
bool cmp3(inq m,inq n){
	int difftb=abs(m.tb-n.tb);
	int diffta=abs(m.ta-n.ta);{
		if(difftb<=diffta){
			return m.tb>n.tb;
		}else{
			return m.ta>n.ta;
		}
	}
}
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans=0;
		int o=0,p=0,q=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].atb=s[i].a-s[i].b,s[i].bta=s[i].b-s[i].a;
			s[i].atc=s[i].a-s[i].c,s[i].cta=s[i].c-s[i].a;
			s[i].btc=s[i].b-s[i].c,s[i].ctb=s[i].c-s[i].b;
			s[i].ca=s[i].a,s[i].cb=s[i].b,s[i].cc=s[i].c;
			s[i].px[1]=s[i].a,s[i].px[2]=s[i].b,s[i].px[3]=s[i].c;
			sort(s[i].px+1,s[i].px+4,greater<int>());
			if(s[i].px[1]==s[i].ca){
				s[i].x=1;
			}else if(s[i].px[2]==s[i].ca){
				s[i].x=2;
			}else if(s[i].px[3]==s[i].ca){
				s[i].x=3;
			}
			if(s[i].px[1]==s[i].cb){
				s[i].y=1;
			}else if(s[i].px[2]==s[i].cb){
				s[i].y=2;
			}else if(s[i].px[3]==s[i].cb){
				s[i].y=3;
			}
			if(s[i].px[1]==s[i].cc){
				s[i].z=1;
			}else if(s[i].px[2]==s[i].cc){
				s[i].z=2;
			}else if(s[i].px[3]==s[i].cc){
				s[i].z=3;
			}
			if(s[i].x==s[i].y&&s[i].y==s[i].z){
				s[i].y++;
				s[i].z+=2;
			}else if(s[i].x==s[i].y){
				s[i].y++;
			}else if(s[i].y==s[i].z){
				s[i].z++;
			}else if(s[i].x==s[i].z){
				s[i].z++;
			}
		}
		for(int i=1;i<=n;i++){
			if(min(s[i].x,min(s[i].y,s[i].z))==s[i].x){
				o++;
				ans+=s[i].a;
				io[o].tb=s[i].atb,io[o].tc=s[i].atc;
			}else if(min(s[i].x,min(s[i].y,s[i].z))==s[i].y){
				p++;
				ans+=s[i].b;
				ip[p].ta=s[i].bta,ip[p].tc=s[i].btc;
			}else{
				q++;
				ans+=s[i].c;
				iq[q].ta=s[i].cta,iq[q].tb=s[i].ctb;
			}
		}
		for(int i=1;i<=n/2;i++){
			if(o>n/2){
				while(o>n/2){
					sort(io+1,io+o+1,cmp1);
					ans-=min(io[o].tb,io[o].tc);
					o--;
					if(io[o].tb<=io[o].tc){
						p++;
						ip[p].ta=io[o].tb*(-1),ip[p].tc=io[o].tc;
					}else{
						q++;
						iq[q].ta=io[o].tc*(-1),iq[q].tb=io[o].tb;
					}
				}
			}else if(p>n/2){
				while(p>n/2){
					sort(ip+1,ip+p+1,cmp2);
					ans-=min(ip[p].ta,ip[p].tc);
					p--;
					if(ip[p].ta<=io[o].tc){
						o++;
						io[o].tb=ip[p].ta*(-1),io[o].tc=ip[p].tc;
					}else{
						q++;
						iq[q].ta=ip[p].ta,iq[q].tb=ip[p].tc*(-1);
					}
				}
			}else if(q>n/2){
				while(q>n/2){
					sort(iq+1,iq+q+1,cmp3);
					ans-=min(iq[q].ta,iq[q].tb);
					q--;
					if(iq[q].ta<=io[o].tb){
						o++;
						io[o].tb=iq[q].tb,io[o].tc=iq[q].ta*(-1);
					}else{
						p++;
						ip[p].ta=iq[q].ta,ip[p].tc=iq[q].tb*(-1);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
