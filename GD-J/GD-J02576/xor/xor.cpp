#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k,y;
vector<int>a(500001);
void fg(int g,int h,int p){
	if(g>n){
		return ;
	}
	p=p^a[g];
	if(p==k){
		fg(g+1,g+1,0);
		y++;
	}else{
		if(g<n){
			fg(g+1,h,p);
		}else{
			return ;
		}
		
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fg(1,1,0);
	cout<<y;
	return 0;
}

