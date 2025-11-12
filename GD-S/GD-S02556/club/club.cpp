#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;

struct stu{
	int a[4];
	int f,s,t;
	int fv;
	int cp;
}s[maxn];

bool cmp(stu a,stu b){
	if(a.cp>b.cp){
		return true;
	}
	if(a.cp==b.cp){
		return a.fv>b.fv;
	}
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int a1,b1,c1,a2,b2,c2;
			cin>>a1>>b1>>c1>>a2>>b2>>c2;
			int ans=max(a1+b2,max(a1+c2,max(b1+a2,max(b1+c2,max(c1+a2,c1+b2)))));
			cout<<ans;
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
				if(s[i].a[1]>=max(s[i].a[2],s[i].a[3])){
					s[i].f=1;
					s[i].fv=s[i].a[1];
					s[i].s=max(s[i].a[2],s[i].a[3])==s[i].a[2]?2:3;
				}
				else if(s[i].a[2]>=max(s[i].a[1],s[i].a[3])){
					s[i].f=2;
					s[i].fv=s[i].a[2];
					s[i].s=max(s[i].a[1],s[i].a[3])==s[i].a[1]?1:3;
				}
				else if(s[i].a[3]>=max(s[i].a[1],s[i].a[2])){
					s[i].f=3;
					s[i].fv=s[i].a[3];
					s[i].s=max(s[i].a[1],s[i].a[2])==s[i].a[1]?1:2;
				}
				s[i].t=6-s[i].f-s[i].s;
				s[i].cp=s[i].a[s[i].f]-s[i].a[s[i].s];
				//cout<<s[i].a[1]<<' '<<s[i].a[2]<<' '<<s[i].a[3]<<' '<<s[i].f<<' '<<s[i].s<<' '<<s[i].t<<' '<<s[i].cp<<endl;
			}
			sort(s+1,s+1+n,cmp);
			int cnt[4]={0,0,0,0},cntmax=n/2;
			//cout<<endl<<endl;
			/*for(int i=1;i<=n;i++){
				cout<<s[i].a[1]<<' '<<s[i].a[2]<<' '<<s[i].a[3]<<' '<<s[i].f<<' '<<s[i].s<<' '<<s[i].t<<' '<<s[i].cp<<endl;

			}*/
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(cnt[s[i].f]<cntmax){
					cnt[s[i].f]++;
					ans+=s[i].fv;
					//cout<<"#"<<s[i].a[s[i].f]<<' '<<s[i].fv<<' '<<ans<<"#"<<endl;
					continue;
				}
				else{
					ans+=s[i].a[s[i].s];
					cnt[s[i].s]++;
					//cout<<"*"<<s[i].a[s[i].s]<<' '<<ans<<"*"<<endl;
					continue;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
