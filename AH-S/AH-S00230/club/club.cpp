#include<bits/stdc++.h>
using namespace std;
int t,n;
struct member{
	int a,b,c;
};
member m[100005];
int sum,a1[100005],b1[100005],c1[100005],x,aa,bb,cc,a2[100005],b2[100005],c2[100005],p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;aa=0;bb=0;cc=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			x=max(max(m[i].a,m[i].b),m[i].c);
			if(x==m[i].a)
			    a2[aa++]=i;
			else if(x==m[i].b)
			    b2[bb++]=i;
			else c2[cc++]=i;
			sum+=x;
			a1[i]=m[i].a-x;
			b1[i]=m[i].b-x;
			c1[i]=m[i].c-x;
		}
		if(aa>n/2){
			for(int i=0;i<aa;i++){
				p[i]=max(b1[a2[i]],c1[a2[i]]);
			}
			sort(p,p+aa);
			for(int i=aa-1;i>=n/2;i--){
				sum+=p[i];
			}
		}else if(bb>n/2){
			for(int i=0;i<bb;i++){
				p[i]=max(a1[b2[i]],c1[b2[i]]);
			}
			sort(p,p+bb);
			for(int i=bb-1;i>=n/2;i--){
				sum+=p[i];
			}
		}else if(cc>n/2){
			for(int i=0;i<cc;i++){
				p[i]=max(b1[c2[i]],a1[c2[i]]);
			}
			sort(p,p+cc);
			for(int i=cc-1;i>=n/2;i--){
				sum+=p[i];
			}
		}
		cout<<sum<<"\n";    
	}
}
