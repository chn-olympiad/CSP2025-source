#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int t,n,ans,answer;
int ana,anb,anc,cna,cnb,cnc;
bool A,B;
struct student{
	int a,b,c;	
	bool ch=true;
}d[maxn];

bool cmpa(student x,student y){
	return x.a>y.a;
}
bool cmpb(student x,student y){
	return x.b>y.b;
}
bool cmpc(student x,student y){
	return x.c>y.c;
}
void zbc(int x){
	answer=max(answer,ans);
	
	if(x>n){
		return;
	}
	
	if(cna<n/2){
		ans+=d[x].a;
		cna++;
		zbc(x+1);
		ans-=d[x].a;
		cna--;
	}
	
	
	if(cnb<n/2){
		ans+=d[x].b;
		cnb++;
		zbc(x+1);
		ans-=d[x].b;
		cnb--;
	}
	
	if(cnc<n/2 && !B){
		ans+=d[x].c;
		cnc++;
		zbc(x+1);
		ans-=d[x].c;
		cnc--;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		
		cin>>n;
		ans=0;
		A=true,B=true;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			d[i].ch=true;
			if(d[i].b!=0) A=false;
			if(d[i].c!=0) B=false;
		}
		if(B){
			if(A){
				sort(d+1,d+1+n,cmpa);
				for(int i=1;i<=n/2;i++){
					ans+=d[i].a;
				}
				cout<<ans<<endl;
				continue;
			}
			
		}
		
		answer=0;
		zbc(1);
		cout<<answer<<endl;
		
	}	
	return 0;
}
