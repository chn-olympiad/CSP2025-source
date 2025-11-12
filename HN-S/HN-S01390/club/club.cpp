#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,r,z,num,sum,a[100010],b[100010],c[100010];
vector<long long> v,w,u;
int main(  ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>l>>r>>z;
			if(l>=r&&l>=z){
				v.push_back(i);
			}
			else if(r>=l&&r>=z){
				w.push_back(i);
			}
			else{
				u.push_back(i);
			}
			a[i]=max(l,max(r,z));
			sum+=a[i];
			if(a[i]==l) b[i]=max(r,z);
			else if(a[i]==r) b[i]=max(l,z);
			else b[i]=max(l,r);
		}
		num=0;
		if(v.size( )>n/2){
			m=v.size( )-n/2;
			for(int i=0;i<v.size( );i++){
				c[++num]=a[v[i]]-b[v[i]];
			}
			sort(c+1,c+num+1);
			for(int i=1;i<=m;i++){
				sum-=c[i];
			}
		}
		else if(w.size( )>n/2){
			m=w.size( )-n/2;
			for(int i=0;i<w.size( );i++){
				c[++num]=a[w[i]]-b[w[i]];
			}
			sort(c+1,c+num+1);
			for(int i=1;i<=m;i++){
				sum-=c[i];
			}
		}
		else if(u.size( )>n/2){
			m=u.size( )-n/2;
			for(int i=0;i<u.size( );i++){
				c[++num]=a[u[i]]-b[u[i]];
			}
			sort(c+1,c+num+1);
			for(int i=1;i<=m;i++){
				sum-=c[i];
			}
		}
		cout<<sum<<endl;
		v.clear( );
		w.clear( );
		u.clear( );
	}
	return 0;
}
