//GZ-s00460 ÄÏ°×ÖÐÑ§ ³Â²©Óî 
#include<bits/stdc++.h>
using namespace std;
int t,s,h[200001],g[200001],p[200001],n;
struct an{
	int d1;
	int d2;
	int d3;
};
an a[200001],m;
int f(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
        h[i]=a[i].d1,g[i]=a[i].d2,p[i]=a[i].d3;
	}
	stable_sort(h+1,h+1+n);
	stable_sort(g+1,g+1+n);
	stable_sort(p+1,p+1+n);
	for(int i=n;i>=1;i--){
	if(h[i]>max(p[i],p[i])&&m.d1<n/2){
	m.d1+=1;	
	//for(int )
	} 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
	f();
}
      return 0; 
}  
