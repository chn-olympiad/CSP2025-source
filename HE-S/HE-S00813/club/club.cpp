#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int m[100001][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ant=0;
		int ant1=0;
		for(int j=1;j<=n;j++){
			cin>>m[j][1]>>m[j][2]>>m[j][3];
			if(m[j][2]==0 && m[j][3]==0){
				ant++;
			}else if(m[j][3]==0 && m[j][2]!=0){
				ant1++;
			}
		}
		if(n==2){
			long long maxx=-1;
			long long k;
			for(int j=1;j<=3;j++){
				for(int c=1;c<=3;c++){
					if(c==j) continue;
					else{
						k=m[1][j]+m[2][c];
						if(maxx<k){
							maxx=k;
						}
					}
				}
			}
			printf("%lld",maxx);
		}else if(ant==n){
			int a[n+1]={0};
			for(int j=1;j<=n;j++){
				a[j]=m[j][1];
			}
			sort(a+1,a+n+1);
			long long l=0;
			for(int j=n;j>n/2;j--){
				l+=a[j];
			}printf("%lld",l);
		} 
		/*
		我真求了
		
		求也得sort :)
		*/ 
//		else if(ant1==n){
//			
//		}
	}
	return 0;
}
