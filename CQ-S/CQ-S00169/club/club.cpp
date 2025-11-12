#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t;
int n;
int x,y,z;//人数 
int cnt;//满意度之和          
struct node{
	int a,b,c;//满意值 
}p[N]; 
bool cmp(node A,node B){
	if(A.a==B.a){
		if(A.b==B.b){
			return A.c>B.c;
		}
		else return A.b>B.b;
	}
	else return A.a>B.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++){
			int r=max(p[i].a,max(p[i].b,p[i].c));
			if(r==p[i].a&&r==p[i].b&&r==p[i].c){
				int u=min(x,min(y,z));
				if(u<(n/2)){
					if(u==x&&u==y&&u==z){
						z++;
					}
					else if(u==x&&u==y&&u!=z){
						y++;
					}
					else if(u==x&&u!=y&&u==z){
						y++;
					}
					else if(u!=x&&u==y&&u==z) {
						z++;
					}
					else if(u==x) {
						x++;
					}
					else if(u==y) {
						y++;
					}
					else if(u==z){
						z++;
					}
					cnt+=p[i].a;
				}
				else continue;
			}
			else if(r==p[i].a&&r==p[i].b&&r!=p[i].c){
				int u=min(x,y);
				if(u<(n/2)){
					if(u==x&&u==y) {
						y++;
					}
					else if(u==x&&u!=y) {
						x++;
					}
					else if(u!=x&&u==y) {
						y++;
					}y++;
					cnt+=p[i].a;
				}
			}
			else if(r==p[i].a&&r!=p[i].b&&r==p[i].c){
				int u=min(x,z);
				if(u<(n/2)){
					if(u==x&&u==z) {
						z++;
					}
					else if(u==x&&u!=z) {
						x++;
					}
					else if(u!=x&&u==z) {
						z++;
					}
					cnt+=p[i].a;
				}
			}
			else if(r!=p[i].a&&r==p[i].b&&r==p[i].c){
				int u=min(z,y);
				if(u<(n/2)){
					if(u==z&&u==y) {
						z++;
					}
					else if(u==z&&u!=y) {
						y++;
					}
					else if(u!=z&&u==y) {
						z++;
					}
					cnt+=p[i].b;
				}
			}
			else if(r==p[i].a&&r!=p[i].b&&r!=p[i].c){
				int u=x;
				if(u<(n/2)){
					x++;
					cnt+=p[i].a;
				}
			}
			else if(r!=p[i].a&&r==p[i].b&&r!=p[i].c){
				int u=y;
				if(u<(n/2)){
					y++;
					cnt+=p[i].b;
				}
			}
			else if(r!=p[i].a&&r!=p[i].b&&r==p[i].c){
				int u=z;
				if(u<(n/2)){
					z++;
					cnt+=p[i].c;
				}
			}
		} 
		cout<<cnt<<"\n";
	}
	return 0;
}

