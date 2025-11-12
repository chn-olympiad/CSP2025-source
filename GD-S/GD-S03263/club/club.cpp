#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct nd{
	int x,y,z;//∂‘”¶123 
	char way,way2;
}a[N];
int t,n,club[N][5];
void solve(){
	for(int i=1;i<=n;i++){
		if(a[i].x>a[i].y){
			if(a[i].x>a[i].z){
				
			}
			if(a[i].x<a[i].z){
				
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		int pn=n/2;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
		}
		solve(); 
	} 
	
} 
