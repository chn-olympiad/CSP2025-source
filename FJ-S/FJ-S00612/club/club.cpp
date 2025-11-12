#include<bits/stdc++.h>
using namespace std;
int n,anss;
int f[100005][5];
int s[5];
queue<int>q;
struct node{
	int x;
	int a,b,c;
}e[100005];
struct h{
	int a,b;
	friend operator<(h a,h b){
		return a.a>b.a;
	}
};
priority_queue<h>qe[5];
void eee(int x){
	int mxm=max(f[x][1],max(f[x][2],f[x][3])),mim=min(f[x][1],min(f[x][2],f[x][3]));
	if(f[x][1]==mxm){
		e[x].a=1;
	}else if(f[x][2]==mxm){
		e[x].a=2;
	}else if(f[x][3]==mxm){
		e[x].a=3;
	}
	if(f[x][1]==mim){
		e[x].c=1;
	}else if(f[x][2]==mim){
		e[x].c=2;
	}else if(f[x][3]==mim){
		e[x].c=3;
	}
	e[x].b=6-e[x].a-e[x].c;
}
bool cmp(node a,node b){
	if(f[a.x][a.a]==f[b.x][b.a]){
		if(f[a.x][a.b]==f[b.x][b.b]) return f[a.x][a.c]>f[b.x][b.c];
		return f[a.x][a.b]>f[b.x][b.b];
	}
	return f[a.x][a.a]>f[b.x][b.a];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		while(!qe[1].empty()) qe[1].pop();
		while(!qe[2].empty()) qe[2].pop();
		while(!qe[3].empty()) qe[3].pop();
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		s[1]=0;
		s[2]=0;
		s[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>f[i][j];
			q.push(i);
			e[i].x=i;
			eee(i);
		} 
		sort(e+1,e+1+n,cmp);
		int sx=n/2;
		int anss=0;
		while(!q.empty()){
			int aa=e[q.front()].a,bb=e[q.front()].b,cc=e[q.front()].c;
			if(s[aa]+1>sx){
				if(f[e[qe[aa].top().b].x][aa]+f[e[q.front()].x][bb]<f[e[qe[aa].top().b].x][bb]+f[e[q.front()].x][aa]){
					q.push(e[qe[aa].top().b].x);
					qe[aa].pop();
					anss+=f[e[q.front()].x][aa]-f[e[qe[aa].top().b].x][aa];
					qe[aa].push({f[e[q.front()].x][aa],q.front()});
				}else{
					if(s[bb]+1>sx){
						if(f[e[qe[bb].top().b].x][bb]+f[e[q.front()].x][cc]<f[e[qe[bb].top().b].x][cc]+f[e[q.front()].x][bb]){
							q.push(e[qe[bb].top().b].x);
							qe[bb].pop();
							anss+=f[e[q.front()].x][bb]-f[e[qe[bb].top().b].x][bb];
							qe[bb].push({f[e[q.front()].x][bb],q.front()});
						}else{
							s[cc]++;
							anss+=f[e[q.front()].x][cc];
							qe[cc].push({f[e[q.front()].x][cc],q.front()});
						}
					}else{
						s[bb]++;
						anss+=f[e[q.front()].x][bb];
						qe[bb].push({f[e[q.front()].x][bb],q.front()});
					}
				}
			}else{
				s[aa]++;
				anss+=f[e[q.front()].x][aa];
				qe[aa].push({f[e[q.front()].x][aa],q.front()});
			}
			q.pop();
		}
		cout<<anss<<endl;
	}
	
	return 0;
}
