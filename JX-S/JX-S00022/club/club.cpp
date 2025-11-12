#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int t;
int cnt=0,ans[4]={0};
long long chose(int x,int y,int z){
	if(x==max(x,y)&&x==max(x,z)){
		return x;
		} 
	if(y==max(x,y)&&y==max(y,z)){
		return y;
		} 
	if(z==max(z,y)&&z==max(x,z)){
		return z;
		} 
		return 0;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans[4]={0};
		long long n,a[M],b[M],c[M];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			}
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			for(int i=n/2+1;i<=n;i++){
				cnt+=chose(a[i],b[i],c[i]);
				}
				cout<<cnt<<endl;
				cnt=0;
		}
		return 0;
	}
