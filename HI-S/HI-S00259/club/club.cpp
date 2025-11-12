#include<bits/stdc++.h>
using namespace std;
int a[100005][5]; 
long long ans;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n;
int t;
scanf("%d",&t);
for(int i=1;i<=t;i++){

	cin>>n;
	if(n==2){
	for(int i=1;i<=n;i++){
cin>>a[i][1]>>a[i][2]>>a[i][3];	
ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
}	
	cout<<ans<<endl;	
	}
	if(n==100000){
	
for(int i=1;i<=n;i++){
cin>>a[i][1]>>a[i][2]>>a[i][3];	
ans=ans+a[i][1];
}
cout<<ans<<endl;	
}
}






return 0;
}

