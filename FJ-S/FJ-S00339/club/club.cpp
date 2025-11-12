#include<bits/stdc++.h>
using namespace std;
int t,ans,n,cu[4],sy,cuu[4];
struct student{
	int m[4];
	int z,z1,z2;
	int c;
	int numm;
	int ligg;
	int bigg;
}s[1000000];
void dh(int x,int y,int k){
	s[x].z=0;
	ans=ans-s[x].c+s[y].m[k];
	//printf(" %d->%d cuu%d\n",y,x,cuu[k]);   //
	if(x==y){
		cuu[k]=s[y].bigg;
		s[s[y].bigg].ligg=0;
	}
	return;
}
void csh(){
	ans=0;
	for(int i=0;i<=n;i++){
		s[i].ligg=0;
		s[i].bigg=0;
	}
	for(int i=0;i<=3;i++){
		cu[i]=0;
		cuu[i]=0;
	}
	return;
}
void pxx(int k,int x,int mm){
	if(cu[k]==1){
		cuu[k]=x;
		return;
	}
	int hh=cuu[k];
	for(int i=1;i<=mm+1;i++){
		if(s[hh].c>=s[x].c){
			if(hh==cuu[k]){
				s[hh].ligg=x;
				s[x].bigg=hh;
				cuu[k]=x;
				return;
			}
			s[x].ligg=s[hh].ligg;
			s[s[hh].ligg].bigg=x;
			s[hh].ligg=x;
			s[x].bigg=hh;
			return;
		}
		if(s[hh].bigg==0){
			s[hh].bigg=x;
			s[x].ligg=hh;
			return;
		}
		hh=s[hh].bigg;
	}
}
int main(){
	freopen("club.in","r",stdin);//!!!!!!!!!!!!!
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		csh();
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>s[j].m[1]>>s[j].m[2]>>s[j].m[3];
			s[j].numm=j;
			if(s[j].m[1]>=s[j].m[2]){
			    s[j].z=1;
			    s[j].z1=2;
			}
			else {
			    s[j].z=2;
			    s[j].z1=1;
			}
			if(s[j].m[s[j].z]<s[j].m[3]) {
			    s[j].z2=s[j].z;
				s[j].z=3;
			}
			else s[j].z2=3;
			s[j].c=min(s[j].m[s[j].z]-s[j].m[s[j].z1],s[j].m[s[j].z]-s[j].m[s[j].z2]);
			cu[s[j].z]+=1;
			pxx(s[j].z,j,cu[s[j].z]);
			if(cu[s[j].z]>n/2){
				cu[s[j].z]-=1;
				if(s[j].m[s[j].z]>=s[cuu[s[j].z]].c&&s[j].m[s[j].z]-s[j].c<=s[j].m[s[j].z]-s[cuu[s[j].z]].c){
					sy=0;
					if(cuu[s[j].z]==j) sy=1;
				    dh(cuu[s[j].z],j,s[j].z);
				    if(sy==1){
				    	sy=0;
					    continue;
					}
					s[s[cuu[s[j].z]].bigg].ligg=0;
				    cuu[s[j].z]=s[cuu[s[j].z]].bigg;
				    s[cuu[s[j].z]].ligg=0;
				    s[cuu[s[j].z]].bigg=0;
				}
				else {
					if(s[j].m[s[j].z]-s[j].c>s[j].m[s[j].z]-s[cuu[s[j].z]].c){
						if(cuu[s[j].z]==j){
							cuu[s[j].z]=s[j].bigg;
							s[s[j].bigg].ligg=0;
						}
						ans=ans+s[j].m[s[j].z]-s[j].c;
						s[s[j].ligg].bigg=s[j].bigg;
				        s[s[j].bigg].ligg=s[j].ligg;
				        continue;
					}
					if(cuu[s[j].z]==j){
						s[s[cuu[s[j].z]].bigg].ligg=0;
				        cuu[s[j].z]=s[cuu[s[j].z]].bigg;
				        s[cuu[s[j].z]].ligg=0;
				        s[cuu[s[j].z]].bigg=0;
					}
				    ans=ans+s[j].m[s[j].z]-s[j].c;
				    s[s[j].ligg].bigg=s[j].bigg;
				    s[s[j].bigg].ligg=s[j].ligg;
				}
				continue;
			}
			ans+=s[j].m[s[j].z];
			//printf(" %d->s%d  \n",j,s[j].z);  //
		}
		cout<<ans<<endl;
	}
	return 0;
}
