 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","W",stdout);
 	int a1,a2,a3;//manyizhi
 	int z1,z2,z3;//shetuan
 	int n,n_1;//renshu
 	int t;
 	int ans=0;
 	cin>>n>>t;
 	n_1=n/2;
 	for(int j=0;j<=t;j++){
 		for(int i=0;i<=n;i++){
 			cin>>a1>>a2>>a3;
 			if(a1>a2 && a1>a3 & z1<=n_1){
 				ans+=a1;
 				z1++;
			}
			if(a2>a1 && a2>a3 & z2<=n_1){
 				ans+=a2;
 				z2++;
			}
			else{
				if(a1=a2){
					if(z1<=z2){
						z1++;
						ans+=a1;
					}
					else{
						z2++;
						ans+=a2;
					}
				if(a1=a3){
					if(z1<=z3){
						z1++;
						ans+=a1;
					}
					else{
						z3++;
						ans+=a3;
					}
				}
				if(a3=a2){
					if(z3<=z2){
						z3++;
						ans+=a3;
					}
					else{
						z2++;
						ans+=a2;
					}
				
				}
			}
	
		}
	
	}
	cout<<ans;
}
 	return 0;
}
