#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}sc[100010];
bool cmp(node aa,node bb){
	return aa.a-max(aa.b,aa.c)>bb.a-max(bb.b,bb.c);
}/*
void outt(node aa){
	cout<<aa.a<<" "<<aa.b<<" "<<aa.c<<"\n";
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T,n,ga,gb,gc;
	scanf("%d",&T);
	while(T--){
		ga=gb=gc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&sc[i].a,&sc[i].b,&sc[i].c);
			if(sc[i].a>sc[i].b and sc[i].a>sc[i].c) ga++;
			else if(sc[i].b>sc[i].a and sc[i].b>sc[i].c) gb++;
			else if(sc[i].c>sc[i].b and sc[i].c>sc[i].a) gc++;
		}
		//cout<<ga<<" "<<gb<<" "<<gc<<endl;
		if(ga>n/2 or gb>n/2 or gc>n/2){
			if(gb>n/2) for(int i=1;i<=n;i++) swap(sc[i].a,sc[i].b);
			else if(gc>n/2) for(int i=1;i<=n;i++) swap(sc[i].a,sc[i].c);
			sort(sc+1,sc+1+n,cmp);
			//outt(sc[1]);
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(sc[i].a>sc[i].b and sc[i].a>sc[i].c){
					if(cnt==n/2) ans=ans+max(sc[i].b,sc[i].c); 
					else cnt++,ans=ans+sc[i].a;
				}else ans=ans+max(sc[i].b,sc[i].c);
			}
			printf("%d\n",ans);
		}else{
			int ans=0;
			for(int i=1;i<=n;i++) ans=ans+max(max(sc[i].a,sc[i].b),sc[i].c);
			printf("%d\n",ans);
		}
	}
	return 0;
}
