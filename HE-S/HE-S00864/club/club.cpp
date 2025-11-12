#include<bits/stdc++.h>
using namespace std;
struct o{
	int a,b,c;
}l[100001];
bool cmpa(o a,o b){
	return a.a-max(a.b,a.c)>b.a-max(b.b,b.c);
}
bool cmpb(o a,o b){
	return a.b-max(a.a,a.c)>b.b-max(b.a,b.c);
}
bool cmpc(o a,o b){
	return a.c-max(a.b,a.a)>b.c-max(b.b,b.a);
}
int t,n,m,ans,ansa,ansb,ansc,fa,fb,fc,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s=ans=ansa=ansb=ansc=fa=fb=fc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
		}
		for(int i=1;i<=n;i++){
			ans+=max(l[i].a,max(l[i].b,l[i].c));
		}
		sort(l+1,l+n+1,cmpa);
		for(int i=1;i<=n/2;i++){
			if(l[i].a<max(l[i].b,l[i].c)){
				break;
			}
			ansa+=l[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			ansa+=max(l[i].b,l[i].c);
		}
		if(l[n/2+1].a>max(l[n/2+1].b,l[n/2+1].c)){
			fa=1;
		}
		sort(l+1,l+n+1,cmpb);
		for(int i=1;i<=n/2;i++){
			if(l[i].b<max(l[i].a,l[i].c)){
				break;
			}
			ansb+=l[i].b;
		}
		for(int i=n/2+1;i<=n;i++){
			ansb+=max(l[i].a,l[i].c);
		}
		if(l[n/2+1].b>max(l[n/2+1].a,l[n/2+1].c)){
			fb=1;
		}
		sort(l+1,l+n+1,cmpc);
		for(int i=n/2+1;i<=n;i++){
			if(l[i].c<max(l[i].a,l[i].b)){
				break;
			}
			ansc+=l[i].c;
		}
		for(int i=n/2+1;i<=n;i++){
			ansc+=max(l[i].a,l[i].b);
		}
		if(l[n/2+1].c>max(l[n/2+1].a,l[n/2+1].b)){
			fc=1;
		}
		s=max(ansa,max(ansb,ansc));
		if(!fa&&!fb&&!fc){
			s=max(s,ans);
		}
		cout<<s<<endl;
	}
	return 0;
} 
