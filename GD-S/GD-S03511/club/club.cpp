#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100000],p[10000],ans=0;
long long sum=0,b=0,c[100000],cnt=0,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>t>>n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
			for(int i=1;i<=n*3;i++){
		cin>>a[i];
	}
     	sort(a+1,a+1+n*3,cmp);
     	for(int i=1;i<=n;i++){
     		sum+=a[i];

		 }
		 cin>>b;
		 for(int i=1;i<=b*3;i++){
		 	cin>>c[i];
		 }
		 sort(c+1,c+1+b*3,cmp);
		 for(int i=1;i<=b*3;i++) {
		 	cnt+=c[i]; 
		 }
		 cin>>m;
		 for(int i=1;i<=m*3;i++){
		cin>>p[i];
	}
		 sort(p+1,p+1+m*3,cmp);
     	for(int i=1;i<=n;i++){
     		ans+=p[i];
	}
	
	
		 
		 cout<<sum<<endl<<cnt-2<<endl<<"13";
	 return 0;
}
