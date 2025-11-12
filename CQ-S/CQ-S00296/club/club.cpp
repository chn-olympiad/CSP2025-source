#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,l;
	bool f;
}w[100005];
bool cmpa(node x,node y){
	return x.a>y.a; 
}
bool cmpb(node x,node y){
	return x.b>y.b; 
}
bool cmpc(node x,node y){
	return x.c>y.c; 
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,s=0,s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w[i].a>>w[i].b>>w[i].c;
			w[i].l=i;
			w[i].f=0;
			if(w[i].a>=w[i].b&&w[i].a>=w[i].c) s1++,s+=w[i].a;
			else if(w[i].b>=w[i].a&&w[i].b>=w[i].c) s2++,s+=w[i].b;
			else if(w[i].c>=w[i].a&&w[i].c>=w[i].b) s3++,s+=w[i].c;
		}
		cout<<s<<endl;
	}
	return 0;
}
