#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001];
struct node{
	long long d,e,cz,type;
};
node s[100001];
long long n,p[4],t;
long long ans;
int cmp(node l,node r){
	return l.cz<r.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		p[1]=p[2]=p[3]=0;
		cin>>n;
    	for(long long i=1;i<=n;i++){
    		cin>>a[i]>>b[i]>>c[i];
    		s[i].d=max(a[i],max(b[i],c[i]));
    		if(s[i].d==a[i]){
    			p[1]++;
    			s[i].e=max(b[i],c[i]);
    			s[i].type=1;
			}
			else if(s[i].d==b[i]){
				p[2]++;
				s[i].e=max(a[i],c[i]);
				s[i].type=2;
			}
			else{
				p[3]++;
				s[i].e=max(a[i],b[i]);
				s[i].type=3;
			}
			s[i].cz=s[i].d-s[i].e;
	    }
	    sort(s+1,s+1+n,cmp);
	    for(int i=1;i<=n;i++){
	    	ans+=s[i].d;
		}
		if(p[1]>n/2){
			for(int i=1;i<=n;i++){
				if(p[1]==n/2){
					break;
				}
				if(s[i].type==1){
					ans-=s[i].cz;
    				p[1]--;				
				}
			}
		}
		if(p[2]>n/2){
			for(int i=1;i<=n;i++){
				if(p[2]==n/2){
					break;
				}
				if(s[i].type==2){
					ans-=s[i].cz;
    				p[2]--;				
				}
			}
		}
		if(p[3]>n/2){
			for(int i=1;i<=n;i++){
				if(p[3]==n/2){
					break;
				}
				if(s[i].type==3){
					ans-=s[i].cz;
    				p[3]--;				
				}
			}
		}
    	cout<<ans<<'\n';
	}
	return 0;
}