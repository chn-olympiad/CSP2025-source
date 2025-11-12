#include<bits/stdc++.h>
using namespace std;
int q,w,e;
int head[1005],edge[1005],val[1005],nex[1005],tot;
void add_(int a,int b,int c){
	nex[++tot]=head[a];
	head[a]=tot;
	edge[tot]=b;
	val[tot]=c;
}
int csf[15],cs[15][1005];
bool css[15];
priority_queue< pair < int, int > > fal;
int co;
int g;
bool gc[1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>q>>w>>e;
	for(int i=1;i<=w;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add_(a,b,c);
		add_(b,a,c);
	}
	for(int i=1+w;i<=e+w;i++){
		cin>>csf[i-w];
		for(int j=1;j<=w;j++){
			cin>>cs[i-w][j];			
		}
	}
	fal.push(make_pair(0,1));
	while(!fal.empty()){
		int a=fal.top().first,b=fal.top().second;
		fal.pop();
				
		if(b>100000){
			css[b/100000]=1;
			co-=a;
			b%=100000;		
		}
		
		if(gc[b])continue;
		gc[b]=1;g++;co-=a;
		if(g==w){break;}
		for(int i=head[b];i;i=nex[i]){
			fal.push(make_pair(-val[i],edge[i]));
			for(int j=1;j<=e;j++){
				if(!css[j])
				fal.push(make_pair(-cs[j][edge[i]]-cs[j][b]-csf[j],edge[i]+j*100000));
				else 
				fal.push(make_pair(-cs[j][edge[i]]-cs[j][b],edge[i]));
			}
		}
		
	}
	cout<<co;

	
	return 0;
}
