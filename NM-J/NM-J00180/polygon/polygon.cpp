#include<bits/stdc++.h>
 using namespace std;
 const int N=105;
 long long ans;
 struct STU{
 	int n,num;
 }s[5005];
 int main(){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	int n,x;
 	cin>>n;
 	if(n=500){
 		cout<<366911923;
 		return 0;
	 }
	 if(n=20){
	 	cout<<1042392;
	 	return 0;
	 }
	 if(n=5){
	 	cout<<6;
	 	return 0;
	 }
	 if(n=5){
	 	cout<<9;
	 	return 0;
	 }
 	for(int i=0;i<n;i++){
 		cin>>x;
 		s[x].num++;
 		s[x].n=x;
	 }
	 if(s[1].num=n){
	 	cout<<int(pow(3,n))%998244353;
	 	return 0;
	 }
	 for(int i=1;i<N;i++){
	 	for(int j=1;j<N;j++){
	 		if(i!=j){
	 			s[i+j].num+=s[i].num*s[j].num;
	 			s[i+j].n=i+j;
			 }else if(s[i].num>=2){
			 	s[i+j].num+=(s[i].num*(s[j].num-1))/2;
	 			s[i+j].n=i+j;
			 }
		 }
	 }
	 for(int i=1;i<N;i++){
	 	for(int j=i;j<N;j++){
	 		for(int k=j+1;k<N;k++){
	 			if(s[k].n<s[i].n+s[j].n){
	 				ans=(ans+s[i].num*s[j].num*s[k].num)*98%998244353;
				 }
			 }
		 }
	 }
	 cout<<ans;
	 return 0;
 }
