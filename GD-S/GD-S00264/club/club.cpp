#include<bits/stdc++.h>
using namespace std;
int n;
struct inf{
	int d,id;
};
struct p{
	inf a,b,c;
}hp[100001];
bool cmp(p x,p y){
	if(x.a.d!=y.a.d){
		return x.a.d>y.a.d;
	}
	else if(x.b.d!=y.b.d){
		return x.b.d>y.b.d;
	}
	else{
		return x.c.d>y.c.d;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>hp[i].a.d>>hp[i].b.d>>hp[i].c.d;
			hp[i].a.id=0;
			hp[i].b.id=1;
			hp[i].c.id=2;
			if(hp[i].a.d<hp[i].b.d){
				swap(hp[i].a,hp[i].b);
			}
			if(hp[i].b.d<hp[i].c.d){
				swap(hp[i].b,hp[i].c);
			}
			if(hp[i].a.d<hp[i].b.d){
				swap(hp[i].a,hp[i].b);
			}
			
		}
		sort(hp+1,hp+n+1,cmp);
		int s=0,abcn[3]={0,0,0};
		for(int i=1;i<=n;i++){
			if(abcn[hp[i].a.id]<(n/2)){
				s+=hp[i].a.d;
				abcn[hp[i].a.id]++;
			}
			else if(abcn[hp[i].b.id]<(n/2)){
				s+=hp[i].b.d;
				abcn[hp[i].b.id]++;
			}
			else{
				s+=hp[i].c.d;
				abcn[hp[i].c.id]++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
} 
