#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans,k;
struct pe{
	int a,b,c;
}s[100005];
struct bd{
	int nu,z,r;
};
bool cmp(bd x,bd y){
	return x.z>y.z;
}
bool cmp2(bd x,bd y){
	return x.z-x.r+x.z<y.z-y.r+y.z;
}
bool cmp3(bd x,bd y){
	return x.r>y.r;
}
bd g[100005],gg[100005],ggg[100005];
int j,jj,jjj;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		j=0;
		jj=0;
		jjj=0;
		cin>>n;
		for(int t=1;t<=n;t++){
			cin>>s[t].a>>s[t].b>>s[t].c;
			int maxx=max(s[t].a,s[t].b);
			maxx=max(maxx,s[t].c);
			if(maxx==s[t].a){
				g[++j].nu=t;
				//cout<<g[j].nu<<" ";
				g[j].z=maxx;
				g[j].r=max(min(max(s[t].a,s[t].b),s[t].c),min(s[t].a,s[t].b))+maxx;
			}else if(maxx==s[t].b){
				gg[++jj].nu=t;
				//cout<<gg[jj].nu;
				gg[jj].z=maxx;
				gg[jj].r=max(min(max(s[t].a,s[t].b),s[t].c),min(s[t].a,s[t].b))+maxx;
			}else{
				ggg[++jjj].nu=t;
				//cout<<ggg[jjj]
				ggg[jjj].z=maxx;
				ggg[jjj].r=max(min(max(s[t].a,s[t].b),s[t].c),min(s[t].a,s[t].b))+maxx;
			}
		}
		sort(g+1,g+1+j,cmp);
		sort(gg+1,gg+1+jj,cmp);
		sort(ggg+1,ggg+1+jjj,cmp);
		for(int t=1;t<=n/2;t++){
			if(t<=j){
				//cout<<1<<" "<<g[t].nu<<endl;
				ans+=g[t].z;		
			}
			if(t<=jj){
				//cout<<2<<" "<<gg[t].nu<<endl;
				ans+=gg[t].z;		
			}
			if(t<=jjj){
				//cout<<3<<" "<<ggg[t].nu<<endl;
				ans+=ggg[t].z;	
			} 
		}
		//cout<<ans<<endl;
		//cout<<j<<" "<<jj<<" "<<jjj;
		if(j>n/2){
			sort(g+1,g+1+n/2,cmp2);
			sort(g+1+n/2+1,g+1+j,cmp);
			//for(int t=1;t<=n/2;t++) cout<<g[t].nu<<" "<<g[t].r<<" "<<g[t].z<<endl;
			//for(int t=n/2+1;t<=n;t++) cout<<g[t].nu<<" "<<g[t].z<<endl;
			int l=1;
			int r=n/2+1;
			while((g[l].r-g[l].z)+g[r].z>g[l].z){
				ans+=(g[l].r-g[l].z)+g[r].z-g[l].z;
				l++;
				r++;
			}
			for(int t=r;r<=j;r++){
				ans+=g[t].r-g[t].z;
			}
		}else if(jj>n/2){
			//cout<<"fsdfsdf";
			sort(gg+1,gg+1+n/2,cmp2);
			sort(gg+1+n/2+1,gg+1+jj,cmp);
			//for(int t=1;t<=n/2;t++) cout<<gg[t].nu<<" "<<gg[t].r<<" "<<gg[t].z<<endl;
			//for(int t=n/2+1;t<=jj;t++) cout<<gg[t].nu<<" "<<gg[t].z<<endl;
			int l=1;
			int r=n/2+1;
			while((gg[l].r-gg[l].z)+gg[r].z>gg[l].z){
				ans+=(gg[l].r-gg[l].z)+gg[r].z-gg[l].z;
				l++;
				r++;
			}
			for(int t=r;r<=jj;r++){
				ans+=gg[t].r-gg[t].z;
			}
		}else if(jjj>n/2){
			sort(ggg+1,ggg+1+n/2,cmp2);
			sort(ggg+1+n/2+1,ggg+1+jjj,cmp);
			for(int t=1;t<=n/2;t++) cout<<ggg[t].nu<<" "<<ggg[t].r-ggg[t].z<<" "<<ggg[t].z<<endl;
			for(int t=n/2+1;t<=jjj;t++) cout<<ggg[t].nu<<" "<<ggg[t].r-ggg[t].z<<" "<<ggg[t].z<<endl;
			int l=1;
			int r=n/2+1;
			while((ggg[l].r-ggg[l].z)+ggg[r].z>ggg[l].z){
				//cout<<(ggg[l].r-ggg[l].z)<<" "<<ggg[r].z<<" "<<ggg[l].z<<endl;
				ans+=(ggg[l].r-ggg[l].z)+ggg[r].z-ggg[l].z;
				//cout<<l<<" "<<r<<endl;
				l++;
				r++;
			}
			//cout<<l<<" "<<r<<" "<<jjj<<endl;
			for(int t=r;r<=jjj;r++){
				ans+=ggg[t].r-ggg[t].z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
