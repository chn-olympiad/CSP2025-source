//GZ-S00115 观山湖区铭苑中学 唐文博
#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
struct Node{
	long long x,y,z;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long N,k;
	cin>>N;
	while(N--){
		long long ans=0,len=0,maxn,ax=0,ay=0,az=0,he=0;
		cin>>k; 
		for(int i=1;i<=k;i++) cin>>a[i].x>>a[i].y>>a[i].z;  
		for(int i=1;i<=k;i++)
		{ 	
			maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(maxn==a[i].x){ax++;}
			if(maxn==a[i].y){ay++;} 
			if(maxn==a[i].z){az++;} 
			he+=maxn;
		} 
		cout<<he<<endl; 
	}
}




