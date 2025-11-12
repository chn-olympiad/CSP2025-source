#include<bits/stdc++.h>
using namespace std;
long long da[6]={0},n,m,sum,i,t;
struct xx{
	int a,b,c,z,zu,zv;
	int xu=0,xv=0,xuv=0;
	
};
bool cm1(xx o,xx p){
	if(o.zv!=p.zv) return o.zv<p.zv;
	return o.z>p.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
for(int ii=1;ii<=t;ii++)
{
	sum=0;
xx s[10009];
long long sh[4]={0};
cin>>n;
m=n/2;
for(i=1;i<=n;i++){
	cin>>s[i].a>>s[i].b>>s[i].c;
	if(s[i].a>s[i].b&&s[i].c<=s[i].a) {
		s[i].xu=1;
		if(s[i].b>=s[i].c) {
			s[i].xv=2;
			s[i].xuv=3;
		}
		else {
			s[i].xv=3;
			s[i].xuv=2;
		}
	}
	if(s[i].b>=s[i].a&&s[i].b>=s[i].c) 
	{
		s[i].xu=2;
		
		if(s[i].a>=s[i].c) {
			s[i].xv=1;
			s[i].xuv=3;
		}
		else {
			s[i].xv=3;
			s[i].xuv=1;
		}
	}
	if(s[i].c>=s[i].a&&s[i].c>=s[i].b) {
		s[i].xu=3;
		if(s[i].b>=s[i].a) {
			s[i].xv=2;
			s[i].xuv=1;
		}
		else {
			s[i].xv=1;
			s[i].xuv=2;
		}
	}
	s[i].z=max(s[i].a,max(s[i].b,s[i].c));
	s[i].zu=min(s[i].a,max(s[i].b,s[i].c));
	s[i].zv=min(s[i].a,min(s[i].b,s[i].c));
}
sort(s+1,s+n+1,cm1);
for(i=1;i<=n;i++)
{
	if(sh[s[i].xu]+1<=m){
		sum+=s[i].z;
		sh[s[i].xu]+=1;
	}
	else {
		if(sh[s[i].xv]+1<=m){
			sum+=s[i].zu;
			sh[s[i].xv]++;
		}
	else {
			sum+=s[i].zv;
			sh[s[i].xuv]++;
		}
	}
}
da[ii]=sum;
}
for(i=1;i<=t;i++) cout<<da[i]<<endl;
	return 0;
}
