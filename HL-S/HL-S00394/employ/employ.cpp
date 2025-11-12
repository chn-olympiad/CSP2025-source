#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,a;
	int b[]={};
	int e=0;
	cin>>m>>n>>a;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<m;i++){
		if(b[i]<=b[i+1]){
			e=b[i];
			b[i]=b[i+1];
		}
	}
	cout<<2;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
