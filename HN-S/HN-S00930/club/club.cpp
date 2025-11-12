#include<bits/stdc++.h>
using namespace std;
const int L=1e5+5; 
long long t,n;
struct node{
	long long a,b,c; 
}p[L];
struct nod{
	long long a,b,c; 
}p1;
bool cmp(node a,node b){
	if(a.b>b.a) return a.b>b.a;
	else return a.b<b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long ans=0;
		cin>>n;
		int n2=n/2;
		for(int j=1;j<=n;j++){
			cin>>p.a[j]>>p.b[i]>>p.c[i];
		}
		sort(p+1,p+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(p1.a>=n2&&p1.b<n2&&p1.c<n2){
				if(p.b[j]>p.c[j]){
					p1.b++;
					ans+=p.b[j];
				} 
				else{
					p1.b++;
					ans+=p.c[j];
				} 
			}
			else if(p1.b>n2&&p1.c<n2&&p1.a<n2){
				if(p.a[j]>p.c[j]){
					p1.a++;
					ans+=p.a[j]; 
				} 
				else{
					p1.c++;
					ans+=p.c[j];
				} 
			}
			else if(p1.c>n2&&p1.b<n2&&p1.a<n2){
				if(p.a[j]>p.b[j]){
					p1.a++;
					ans+=p.a[j];
				} 
				else{
					p1.b++;
					ans+=p.b[j];
				}  
			}
			else{
				if(p.a[j]>p.b[j]&&p.a[j]>p.c[j]){
					p1.a++;
					ans+=p.a[j];
				} 
				if(p.b[j]>p.a[j]&&p.b[j]>p.c[j]){
					p1.b++;
					ans+=p.b[j];
				} 
				if(p.c[j]>p.b[j]&&p.c[j]>p.a[j]){
					p1.c++;
					ans+=p.c[j];
				} 
			}
		}
		cout<<ans; 
	}
	return 0;
}
