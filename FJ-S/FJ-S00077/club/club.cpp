#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int t,n;
long long ans=0;
struct q{
	int x,y,z,r,c;
}a[N];
vector<q>f,s,k;
bool cmp(q g,q h){
	return g.c>h.c;
}
bool cmq(q g,q h){
	return g.c>h.c;
}
bool chp(q g,q h){
	return g.c>h.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>t;t--;){
		cin>>n,ans=0;
		f.clear(),s.clear(),k.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(a[i].y>=a[i].z){
					a[i].r=2;
					a[i].c=a[i].x-a[i].y;
				}else{
					a[i].r=3;
					a[i].c=a[i].x-a[i].z;
				}
				f.push_back(a[i]);
			}else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				if(a[i].x>=a[i].z){
					a[i].r=1;
					a[i].c=a[i].y-a[i].x;
				}else{
					a[i].c=a[i].y-a[i].z;
					a[i].r=3;
				}
				s.push_back(a[i]);
			}else{
				if(a[i].x>=a[i].y){
					a[i].c=a[i].z-a[i].x;
					a[i].r=1;
				}else{
					a[i].c=a[i].z-a[i].y;
					a[i].r=2;
				}
				k.push_back(a[i]);
			}
		}
		if(f.size()>n/2||s.size()>n/2||k.size()>n/2){
			if(f.size()>n/2){
				sort(f.begin(),f.end(),cmp);
				for(int i=n/2;i<f.size();i++){
					if(2==f[i].r){
						s.push_back(f[i]);
					}else{
						k.push_back(f[i]);
					}
					f[i].x=0,f[i].y=0,f[i].z=0,f[i].r=0;
				}
			}else if(s.size()>n/2){
				sort(s.begin(),s.end(),cmq);
				for(int i=n/2;i<s.size();i++){
					if(1==s[i].r){
						f.push_back(s[i]);
					}else{
						k.push_back(s[i]);
					}
					s[i].x=0,s[i].y=0,s[i].z=0,s[i].r=0;
				}				
			}else{
				sort(k.begin(),k.end(),chp);
				for(int i=n/2;i<k.size();i++){
					if(2==k[i].r){
						s.push_back(k[i]);
					}else{
						f.push_back(k[i]);
					}
					k[i].x=0,k[i].y=0,k[i].z=0,k[i].r=0;
				}				
			}
		}
		for(int i=0;i<f.size();i++){
			ans+=f[i].x;
		}
		for(int i=0;i<s.size();i++){
			ans+=s[i].y;
		}
		for(int i=0;i<k.size();i++){
			ans+=k[i].z;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
