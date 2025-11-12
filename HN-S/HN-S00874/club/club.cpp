#include<bits/stdc++.h>
using namespace std;
int t;
struct edge{
	int a;
	int b;
	int c;
};
bool cmp(edge m,edge m1){
	return m.a>m1.a;
}
/*struct edge1{
	int a;
	int p;
};
bool cmp(edge m,edge m1){
	int k=max(m.a,max(m.b,m.c)),k1=max(m1.a,max(m1.b,m1.c));
	return k>k1;
}

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,c[3]={0},n;
		edge e[100010];
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		sort(e+1,e+1+n,cmp);
		for (int i=1;i<=n;i++){
			edge1 e1[3];
			e1[0].a=e[i].a;
			e1[0].p=0;
			e1[1].a=e[i].b;
			e1[1].p=1;
			e1[2].a=e[i].c;
			e1[2].p=2;
			sort(e1,e1+3,cmp1);
			for (int j=0;j<3;j++){
				if(c[e1[j].p]<n/2){
					c[e1[j].p]++;
					ans+=e1[j].a;
					//cout<<e1[j].a<<" "<<e1[j].p<<endl;
					continue;
				}	
			}
		}
		cout<<ans<<endl;	
		//for (int i=0;i<3;i++) cout<<c[i]<<" ";
		//cout<<endl;	
	}
	return 0;
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		edge e[100010];
		int ans=0,n;
		cin>>n;
		
		for(int i=1;i<n+1;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		sort(e+1,e+n+1,cmp);
		for (int i=1;i<=n/2;i++){
			ans+=e[i].a;
		}	
		cout<<ans<<endl;
	}
	return 0;
}

