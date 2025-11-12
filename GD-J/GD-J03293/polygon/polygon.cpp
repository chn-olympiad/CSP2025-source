#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 1005
ll n,a[Max]; 
ll max_,ans;
struct pai{
	int l,r;
}b[Max];
ll op;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
     cin>>n;
     for(int i=0;i<n;i++){
     	cin>>a[i];
	 }
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		max_=0;
	 		ans=0;
	 	 for(int k=i;k<=j;k++){
	 	   	ans+=a[k],max_=max(max_,a[k]);
		  }	
		if(ans>max_*2){
			b[op].l=i+1,b[op].r=j+1,op++;
		}
		}
	 }
//	 for(int i=0;i<op;i++){
//	 	cout<<b[i].l<<" "<<b[i].r<<endl;
//	 }
cout<<op;
	return 0;
} 

