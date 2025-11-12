#include<iostream>
#include<cmath>
using namespace std;
//struct  pe(){
//	int a[100000];
//}pe[3];
int gcd(int x,int y){
	return x>y;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int cnt=0;
	int v1,v2,v3;
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v1>>v2>>v3;

			
			cnt=cnt+max(max(v1,v2),v3);				
		}
		cout<<cnt;
}
	
	return 0;	
	}
	
	

