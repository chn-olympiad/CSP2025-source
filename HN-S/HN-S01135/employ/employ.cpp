#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long mod=998244353,jlqpl[1001]={},n,m,s[1001]={},book[1001]={},c[1001]={},tc[1001]={},jl=0,ans=1;
long long pdpd(){
	long long pda=0;/*
	for(long long i=0;i<n;i++){
		cout<<jlqpl[i]<<" ";
	}*/
	//cout<<endl;
	for(long long i=0;i<n;i++){
		if(s[i]&&tc[jlqpl[i]]>=i){
			//cout<<tc[jlqpl[i]]<<" ";
			pda++;
		}
	}
	if(pda>=m){
	//	cout<<endl;
		ans++;
	}
}
long long bfs(long long sz){
	if(sz==n){
		pdpd();
	}
	for(long long i=0;i<n;i++){
		if(!book[i]){
			book[i]=1;
			jlqpl[sz]=i;
			bfs(sz+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		char ab;
		cin>>ab;
		s[i]=ab-'0';
		jl+=s[i];
		//cout<<s[i]<<endl;
	}
	for(long long i=0;i<n;i++){
		cin>>c[i];
		tc[i]=-1;
	}
	long long pd=1;
	for(long long i=0;i<m;i++){
		if(!s[i]){
			pd=0;
			break;
		}
	}
	if(pd){
		for(long long i=n;i>1;i--){
			ans*=n;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		long long abab=0;
		for(long long i=0;i<n;i++){
			if(!s[i]){
				abab++;
			}
			for(long long j=0;j<n;j++){
				if(c[j]>abab){
					tc[j]=i;
				}
			}
		}
		ans=0;
		bfs(0);
		cout<<ans;
	}
}

