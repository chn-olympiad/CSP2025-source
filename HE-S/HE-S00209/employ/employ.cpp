#include<bits/stdc++.h>
using namespace std;
struct node{
	int va,ii;
};
node a[100010];
node b[100010];
node c[100010];
bool visa[100010];
bool visb[100010];
int abc[100010][3];
bool cmp(node poi,node oiu){
	return poi.va>oiu.va;
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i].va>>b[i].va>>c[i].va;
		a[i].ii=i;
		b[i].ii=i;
		c[i].ii=i;
		abc[i][1]=a[i].va;
		abc[i][2]=b[i].va;
		abc[i][3]=c[i].va;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
	long long ans=0;
	int jsqa=0,jsqb=0,jsqc=0;
	for(int i=1; i<=n/2; i++){
		ans+=a[i].va;
		visa[a[i].ii]=1;
	}
	for(int i=1; i<=n; i++){
		if(jsqb<=n/2-1){
			if(visa[b[i].ii]==0){
				ans+=b[i].va;
				visb[b[i].ii]=1;
				jsqb++;
			}else{
				if(b[i].va>abc[b[i].ii][1]){
					ans-=abc[b[i].ii][1];
					ans+=b[i].va;
					jsqb++;
					visa[b[i].ii]=0;
					visb[b[i].ii]=1;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(jsqc<=n/2-1){
			if(visa[c[i].ii]==1){
				if(c[i].va>abc[c[i].ii][1]){
					ans-=abc[c[i].ii][1];
					ans+=c[i].va;
					jsqc++;
				}
			}else{
				if(visb[c[i].ii]==1){
					if(c[i].va>abc[c[i].ii][2]){
						ans-=abc[c[i].ii][2];
						ans+=c[i].va;
						jsqc++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
