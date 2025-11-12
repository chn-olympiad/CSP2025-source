#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a;
	int b;
	int c;
}m[100010];
int tak(int q,int s,int an,int bn,int cn){
	if(q>n){
		return s;
	}
	if(an>=n/2){
		s+=max(tak(q+1,s+m[q].b,an,bn+1,cn),tak(q+1,s+m[q].c,an,bn,cn+1));
	}
	else if(bn>=n/2){
		s+=max(tak(q+1,s+m[q].a,an+1,bn,cn),tak(q+1,s+m[q].c,an,bn,cn+1));
	}
	else if(cn>=n/2){
		s+=max(tak(q+1,s+m[q].a,an+1,bn,cn),tak(q+1,s+m[q].b,an,bn+1,cn));
	}
	else{
		s+=max(tak(q+1,s+m[q].a,an+1,bn,cn),max(tak(q+1,s+m[q].b,an,bn+1,cn),tak(q+1,s+m[q].c,an,bn,cn+1))); 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		cout<<tak(1,0,0,0,0)<<endl;
	}
	return 0;
}
