#include<bits/stdc++.h>
using namespace std;
long long b;
long long c,d=0;
int main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     long long m,n;
     cin>>m>>n;
     int a[m];
     for(int i=0;i<m;i++){
		 cin>>a[i];
	 }
	 while(d<m){
		 b=a[d];
		 for(int j=d;j<m;j++){
			 if(j!=d){
				 b=b^a[j];
			 }
			 if(b==n){
				 c++;
				 d=j;
				 break;
			 }
		 }
		 d++;
	 }
	 cout<<c;
     return 0;                       
}
