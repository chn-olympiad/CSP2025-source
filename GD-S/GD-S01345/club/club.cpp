#include<bits/stdc++.h>
using namespace std;
struct people{
	int x;
	int y;
	int z;
};
bool cmp1(people a,people b){
	return a.x >b.x ;
}
bool cmp2(people a,people b){
	return a.y >b.y ;
}
bool cmp3(people a,people b){
	return a.z >b.z ;
}
queue<people> q;
int a1,b1,c1;
int n;
people a[10005];
people b[10005];
people c[10005];
void tryin(people p,int i,bool a2,bool b2,bool c2){
	if(i == 1){
		if(a1+1<=n/2){
			a[++a1] = p;
			return;
		}else{
			if(p.x +a[a1].y>a[a1].x+p.y){
				tryin(a[a1],2,1,1,0);
				a[a1] = p;
				return;
			}else if(p.x +a[a1].z>a[a1].x+p.z){
				tryin(a[a1],3,1,0,1);
				a[a1] = p;
				return;
			}else{
				if(p.y >p.z&&!b2) tryin(p,2,a2,1,c2);
				if(!c2)tryin(p,3,a2,b2,1);
				else tryin(p,2,a2,1,c2);
			}
		}
	}else if(i==2){
		if(b1+1<=n/2){
			b[++b1] = p;
			return;
		}else{
			if(p.y +b[b1].x>b[b1].y+p.x){
				tryin(b[b1],1,1,1,0);
				b[b1] = p;
				return;
			}else if(p.y+b[b1].z>b[b1].y+p.z){
				tryin(b[b1],3,0,1,1);
				b[b1] = p;
				return;
			}else{
				if(p.x >p.z&&!a2) tryin(p,1,1,b2,c2);
				if(!c2)tryin(p,3,a2,b2,1);
				else tryin(p,1,1,b2,c2);
			}
		}
	}else{
		if(c1+1<=n/2){
			c[++c1] = p;
			return;
		}else{
			if(p.z +c[c1].y>c[c1].z+p.y){
				tryin(c[c1],2,0,1,1);
				c[c1] = p;
				return;
			}else if(p.z +c[c1].x>c[c1].z+p.x){
				tryin(c[c1],1,1,0,1);
				c[c1] = p;
				return;
			}else{
				if(p.y >p.x&&!b2) tryin(p,2,a2,1,c2);
				if(!b1)tryin(p,1,1,b2,c2);
				else tryin(p,2,a2,1,c2);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	while(m--){
		int sum = 0;
		cin>>n;
		people s;
		for(int i = 1;i<=n;i++){
			cin>>s.x>>s.y>>s.z;
			q.push(s); 
		}
		while(!q.empty()){
			people p = q.front();
			q.pop();
			if(p.x == max(p.z,max(p.x,p.y))){
				tryin(p,1,false,false,false);
				sort(a+1,a+a1+1,cmp1);
			}else if(p.y == max(p.z,max(p.x,p.y))){
				tryin(p,2,false,false,false);
				sort(b+1,b+b1+1,cmp2);
			}else{
				tryin(p,3,false,false,false);
				sort(c+1,c+c1+1,cmp3);
			}
		}
			for(int i = 1;i<=a1;i++){
				sum+=a[i].x ;
			}
			for(int i = 1;i<=b1;i++){
				sum+=b[i].y ;
			}
			for(int i = 1;i<=c1;i++){
				sum+=c[i].z ;
			}
			cout<<sum<<endl;
			a1 = 0;
			b1 = 0;
			c1 = 0;
	}
	return 0;
} 
