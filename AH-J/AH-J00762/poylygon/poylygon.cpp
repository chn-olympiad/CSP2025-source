#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],ans;
bool v[50005];
int fun(int x,int s,int z,int y){
	if(x==0&&s>2*z){
		ans++;
	}
	for(int i=y;i<=n;i++){
		if(v[i]!=1){
			v[i]=1;
			int t=0;
			if(x==1){
				t=i;
			}
			fun(x-1,s+a[i],t,i+1);
			v[i]=0;
		}
	}
}
int main(){
     freopen("poylygon.in","r",stdin);
     freopen("poylygon.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
		 cin>>a[i];
	 }
	 sort(a+1,a+n+1);
	 for(int i=3;i<=n;i++){
		 fun(i,0,0,1);
	 }
	 cout<<ans;
     return 0;
}
