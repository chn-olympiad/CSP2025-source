#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,x,y,club;
}st[100005];
int club[4];
int t,n;
int ans=0;
bool cmp(node a,node b){
	if(a.x==b.x) return a.y>b.y;
	return a.x>b.x;
}
int get_mx(node a){
	if(a.a>a.b){
		if(a.a>a.c) return 1;
		else return 3;
	}else{
		if(a.b>a.c) return 2;
		else return 3;
	}
}
int get_nt(node a){
	if(a.a>a.b){
		if(a.b>a.c) return 2;
		if(a.c>a.a) return 1;
		else return 3;
	}else{
		if(a.c>a.b) return 2;
		if(a.c>a.a) return 3;
		else return 1;
	}
}
int get_mi(node a){
	if(a.a>a.b){
		if(a.b>a.c) return 3;
		else return 2;
	}else{
		if(a.c>a.a) return 1;
		else return 3;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
			if(st[i].a>st[i].b){
				if(st[i].a>st[i].c) st[i].x=min(st[i].a-st[i].b,st[i].a-st[i].c),st[i].y=max(st[i].a-st[i].b,st[i].a-st[i].c)-st[i].x;
				else st[i].x=st[i].c-st[i].a,st[i].y=st[i].a-st[i].b;
			}else{
				if(st[i].b>st[i].c) st[i].x=min(st[i].b-st[i].a,st[i].b-st[i].c),st[i].y=max(st[i].b-st[i].a,st[i].b-st[i].c)-st[i].x;
				else st[i].x=st[i].c-st[i].b,st[i].y=st[i].b-st[i].a;
			}
		}
		sort(st+1,st+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(club[get_mx(st[i])]<n/2) st[i].club=get_mx(st[i]),club[get_mx(st[i])]++;
			else if(club[get_nt(st[i])]<n/2) st[i].club=get_nt(st[i]),club[get_nt(st[i])]++;
			else st[i].club=get_mi(st[i]),club[get_mi(st[i])]++;
			if(st[i].club==1) ans+=st[i].a;
			else if(st[i].club==2) ans+=st[i].b;
			else ans+=st[i].c;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
