#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long a,b,c[10000][10000],d[10000],e=1,num=0,mx=0;
	cin>>a;
    for(long long k=1;k<=a;k++){
		cin>>b;
		for(long long i=1;i<=b;i++){
			for(long long j=1;j<=3;j++){
				cin>>c[i][j];
			}
		}
		for(long long m=1;m<=b;m++){
			
			if(c[m][e]>mx){
				mx=c[m][e];
				if(e<3){
					e++;
				}
				else{
				    d[m]=mx;
				    mx=0;
				    e=1;
					continue;
				}
				
			}
		}
		for(long long n=1;n<=b;n++){
			num+=d[n];
		}
		cout<<num<<endl ;
	}
	return 0;
	
}
	

