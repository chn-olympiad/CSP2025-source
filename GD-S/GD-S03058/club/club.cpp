#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
struct node{
	int a,b,c,mx,cmx,mi,mxi,cmxi,mii;
}s[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				s[i].mx=s[i].a;
				s[i].mxi=1;
				if(s[i].b>=s[i].c){
					s[i].cmx=s[i].b;
					s[i].cmxi=2;
					s[i].mi=s[i].c;
					s[i].mii=3;
				}
				else{
					s[i].cmx=s[i].c;
					s[i].cmxi=3;
					s[i].mi=s[i].b;
					s[i].mii=2;
				}
			}
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				s[i].mx=s[i].b;
				s[i].mxi=2;
				if(s[i].a>=s[i].c){
					s[i].cmxi=1;
					s[i].mii=3;
					s[i].cmx=s[i].a;
					s[i].mi=s[i].c;
				}
				else{
					s[i].cmxi=3;
					s[i].mii=1;
					s[i].cmx=s[i].c;
					s[i].mi=s[i].a;
				}
			}
			else{
				s[i].mxi=3;
				s[i].mx=s[i].c;
				if(s[i].a>=s[i].b){
					s[i].cmxi=1;
					s[i].mii=2;
					s[i].cmx=s[i].a;
					s[i].mi=s[i].b;
				}
				else{
					s[i].cmxi=2;
					s[i].mii=1;
					s[i].cmx=s[i].b;
					s[i].mi=s[i].a;
				}
			}
		}
		priority_queue<pair<int,pair<int,int> > >q1;
		priority_queue<pair<int,pair<int,int> > >q2;
		priority_queue<pair<int,pair<int,int> > >q3;
		int pp1=0,pp2=0,pp3=0;
		for(int i=1;i<=n;i++){
			if(s[i].mxi==1){
				if(pp1>=n/2){
					pair<int,pair<int,int> >t=q1.top();
					int zhi=-t.second.first;
					int num=t.second.second;	
					if(zhi+s[i].cmx<s[num].cmx+s[i].mx){
						q1.pop();
						q1.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
						if(s[num].cmxi==2)q2.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
						else q3.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
					}
					else{
						if(s[i].cmxi==2)q2.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
						else q3.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
					}
					continue;
				}
				q1.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
				pp1++;
			}
			else if(s[i].mxi==2){
				if(pp2>=n/2){
					pair<int,pair<int,int> >t=q2.top();
					int zhi=-t.second.first;
					int num=t.second.second;	
					if(zhi+s[i].cmx<s[num].cmx+s[i].mx){
						q2.pop();
						q2.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
						if(s[num].cmxi==1)q1.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
						else q3.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
					}
					else{
						if(s[i].cmxi==1)q1.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
						else q3.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
					}
					continue;
				}
				q2.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
				pp2++;
			}
			else if(s[i].mxi==3){
				if(pp3>=n/2){
					pair<int,pair<int,int> >t=q3.top();
					int zhi=-t.second.first;
					int num=t.second.second;	
					if(zhi+s[i].cmx<s[num].cmx+s[i].mx){
						q3.pop();
						q3.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
						if(s[num].cmxi==1)q1.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
						else q2.push({-(s[num].mx-s[num].cmx),{-s[num].cmx,num}});
					}
					else{
						if(s[i].cmxi==1)q1.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
						else q2.push({-(s[i].mx-s[i].cmx),{-s[i].cmx,i}});
					}
					continue;
				}
				q3.push({-(s[i].mx-s[i].cmx),{-s[i].mx,i}});
				pp3++;
			}
		}
		int sum=0;
		while(!q1.empty()){
			sum-=q1.top().second.first;
			q1.pop();
		}
		while(!q2.empty()){
			sum-=q2.top().second.first;
			q2.pop();
		}
		while(!q3.empty()){
			sum-=q3.top().second.first;
			q3.pop();
		}
		cout<<sum<<"\n";
	}
	return 0;
}
