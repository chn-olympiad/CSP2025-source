#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct s{
	int x,y,z,mx,mb,f1,f2;
}e[N];
int t,n,a[4],ans;
void init(){
	ans=0;
	for(int i=1;i<=3;i++)
	a[i]=0;
	for(int i=1;i<=n;i++)
	e[n].x=e[n].y=e[n].z=0;
}
bool cmp(s a,s b){
	return(a.x+a.y+a.z>b.x+b.y+b.z);
}
int find_max(int x){
	int q=max(e[x].y,e[x].z);
	if(e[x].x>=q)
	return 1;
	q=max(e[x].x,e[x].z);
	if(e[x].y>=q)
	return 2;
	return 3;
}
int find(int x){
	int q=max(e[x].y,e[x].z);
	if(e[x].x>=q){
		if(e[x].y>=e[x].z)
		return 2;
		else return 3;
		}
		
	q=max(e[x].x,e[x].z);
	if(e[x].y>=q){
		if(e[x].x>=e[x].z)
		return 1;
		else return 3;
		}
		
	if(e[x].x>=e[x].y)
	return 1;
	return 2;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>e[i].x>>e[i].y>>e[i].z;
		for(int i=1;i<=n;i++)	
				if(find_max(i)==1){
					e[i].mx=e[i].x;
					e[i].f1=1;
				}	
				else
					if(find_max(i)==2){
						e[i].mx=e[i].y;
						e[i].f1=2;
					}
					else 
						if(find_max(i)==3){
							e[i].mx=e[i].z;
							e[i].f1=3;
						}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++)	
			if(find(i)==1){
				e[i].mb=e[i].x;
				e[i].f2=1;
			}	
			else
				if(find(i)==2){
					e[i].mb=e[i].y;
					e[i].f2=2;
				}
				else 
					if(find(i)==3){
						e[i].mb=e[i].z;
						e[i].f2=3;
					}
					
		for(int i=1;i<=n;i++){
			if(a[e[i].f1]<n/2){
				ans+=e[i].mx;
				a[e[i].f1]++;
			}
			else{
				ans+=e[i].mb;
				a[e[i].f2]++;
			}
		}
		cout<<ans<<'\n';
		init();
	}
	
	return 0;
}
