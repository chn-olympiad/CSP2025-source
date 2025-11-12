#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=0;i<t;i++){
		long long n,a[10001][11]={},jl[10001][11]={},ans=0;
		cin>>n;
		for(long long i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(long long i=0;i<n/2;i++){
			jl[i][0]=a[i][0];
			jl[i][1]=a[i][1];
			jl[i][2]=a[i][2];
			ans+=jl[i][0];
		}
		for(long long i=n/2;i<n;i++){
			long long pd=1,jlzb=0,num=max(a[i][1],a[i][2]);
			for(long long j=0;j<n/2;j++){
				if(num<max(jl[j][1],jl[j][2])-jl[j][0]+a[i][0]){
					num=max(jl[j][1],jl[j][2])-jl[j][0]+a[i][0];
					jlzb=j;
					pd=0;
				}
			}
			if(!pd){
				jl[jlzb][0]=a[i][0];
				jl[jlzb][1]=a[i][1];
				jl[jlzb][2]=a[i][2];
			}
			ans+=num;
			//cout<<num<<endl;
		}
		cout<<ans<<endl;
	}
}
