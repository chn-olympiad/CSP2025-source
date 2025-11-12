#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[105];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int mx=-1e9,mn=1e9,mx1=-1e9,mn1=1e9,mx2=-1e9,mn2=1e9;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(n==1&&m==1){
			cout<<"1 1";
			break;
	 	}
	 	
	 	if(n==1&&m==2){
	 		mx=max(a[1],a[2]);
	 		if(mx==a[1]){
	 			cout<<"1 1";
	 			break;
			 }else{
			 	cout<<"1 2";
			 	break;
			 }
		 }
		 
		 if(n==1&&m==3){
		 	mx=max(a[1],max(a[2],a[3]));
		 	if(mx==a[1]){
		 		cout<<"1 1";
		 		break;
			 }else{
			 	mn=min(a[1],min(a[2],a[3]));
			 	if((mx==a[2]||mx==a[3])&&mn==a[1]){
			 		cout<<"1 3";
			 		break;
				 }else{
				 	if((mx==a[2]||mx==a[3])&&mn==a[3]){
				 		cout<<"1 2";
				 		break;
				 	}
				 }
			 }
		 }
		 
		 if(n==2&&m==2){
		 	mx1=max(a[2],max(a[3],a[4]));
		 	mx=max(a[1],mx1);
		 	mn1=min(a[2],min(a[3],a[4]));
		 	mn=min(a[1],mn1);
		 	if(mx==a[1]){
		 		cout<<"1 1";
		 		break;
			 }else{
			 	if((mx==a[2]||mx==a[3]||mx==a[4])&&mn==a[1]){
			 		cout<<"2 2";
			 		break;
				 }else{
				 	if(mx==a[2]){
				 		mx2=max(a[1],max(a[3],a[4]));
				 		if(mx2==a[1]){
				 			cout<<"1 2";
				 			break;
						 }else{
						 	if((a[3]>a[1]&&a[1]>a[4])||(a[4]>a[1]&&a[1]>a[3])){
						 		cout<<"2 1";
						 		break;
							 }
						 }
					 }
				 }
			 }
		 }
		 
		 
	}
		 return 0;
}
	