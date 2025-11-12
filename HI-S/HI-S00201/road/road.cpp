#include<bits/stdc++.h>
using namespace std;
struct ma{
	long long A,B,C;
};
long long fa[10005],b[10005];
bool bj[10005]; 
vector<ma> a; 
long long find(long long x){
	if(fa[x]==0) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void f(long long x,long long y){
	long long l=find(x);
	fa[find(y)]=l;
}
bool ab(ma x,ma y){
	return x.C<y.C;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	 long long n,m,k,ans=0;
	 cin>>n>>m>>k;
	 for(long long c=1;c<=m;c++){
	 	long long x,y,z;
	 	cin>>x>>y>>z;
	 	a.push_back(ma{x,y,z});
	 }
	 sort(a.begin(),a.end(),ab);
	 for(long long c=0;c<a.size();c++){
	 	if(find(a[c].A)==find(a[c].B)) continue;
	 	ans+=a[c].C;
	 	f(a[c].A,a[c].B);
	 	if(bj[a[c].A]==0){
	 		b[a[c].A]=a[c].C;
	 		bj[a[c].A]=1;
		 } 
	 	else{
	 		b[a[c].B]=a[c].C;
	 		bj[a[c].B]=1;
		 } 
	 }
	 long long q[10005];
	 q[0]=1000000000000000000;
	 for(long long i=1;i<=k;i++){
	 	long long x,an=0,min_=0,min_1=0;
	 	cin>>x;
	 	for(long long c=1;c<=n;c++){
	 		cin>>q[c];
	 		if(q[c]<q[min_]){
	 			min_1=min_;
	 			min_=c;
			}
			else{
				if(q[min_1]>q[c]) min_1=c;
			}
		 } 
	 	for(int c=1;c<=n;c++){
	 		if(bj[c]==0){
	 			if(min_==c) q[c]=q[min_1]+q[c];
			     else an+=q[min_]+q[c];
			     bj[c]=1;
	 			continue;
			 } 
	 		if(min_==c&&b[c]>q[min_1]+q[c]) an+=b[c]-q[min_1]-q[c];
			else if(b[c]>q[min_]+q[c]) an+=b[c]-q[min_]-q[c];
		 }
		 if(an>x){
		 	ans=ans-an+x;
		 	for(int c=1;c<=n;c++){
	 		  if(min_==c&&b[c]>q[min_1]+q[c]) b[c]=q[min_1]+q[c];
			  else if(b[c]>q[min_]+q[c]) b[c]=q[min_]+q[c];
		   }
		 }
	 }
	 cout<<ans;
	return 0;
}
