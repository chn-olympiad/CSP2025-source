#include<bits/stdc++.h>

using namespace std;

int cv[505];
bool vi[505];
string k;

int ct=0;
int n;
int k2=0;

void dfs(int a,int b2,int b){
	if(a+n-b<k2)return;
	if(b==n){
		ct+=(a>=k2);
		ct%=988244353;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vi[i]){
			//cout<<cv[i]<<">"<<b2<<endl;
			if(cv[i]>b2){
				vi[i]=1;
				dfs(a+k[b]-'0',b2+'1'-k[b],b+1);
				vi[i]=0;
			}
			else{
				vi[i]=1;
				dfs(a,b2+1,b+1);
				vi[i]=0;
			}
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>k2;
	
	cin>>k;
	
	for(int i=0;i<n;i++){
		cin>>cv[i];
	}	
	
	dfs(0,0,0);
	
	cout<<ct;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
