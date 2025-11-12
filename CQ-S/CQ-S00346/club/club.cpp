#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b,c;
	bool p=0;
};
bool cmp(S x,S y){
	return x.a>y.a;
}
bool cmp1(S x,S y){
	return x.b>y.b;
}
bool cmp2(S x,S y){
	return x.c>y.c;
}
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t;
 	cin>>t;
 	while(t--){
 		int n,c=0;
 		cin>>n; 
 		S s[n];
 		for(int i=0;i<n;i++){
 			cin>>s[i].a>>s[i].b>>s[i].c;
		 }
		 sort(s,s+n,cmp);
		 for(int i=0;i<n/2;i++){
		 	c+=s[i].a;
		 	s[i].p=1;
		 }
		 sort(s,s+n,cmp1);
		 for(int i=0;i<n/2;i++){
		 	if(s[i].p==0){
		 		c+=s[i].c;
		 	s[i].p=1;
			 }
		 }
		 sort(s,s+n,cmp2);
		 for(int i=0;i<n/2;i++){
		 	if(s[i].p==0){
		 		c+=s[i].c;
		 	s[i].p=1;
			 }
		 }
		 cout<<c<<endl;
	 }
 	
 	return 0;
 }
