#include<iostream>
using namespace std;
long long  k[10000][3];
int date[5][3];
long maxx(long long a,long long b,long long c){
	if(a>=b){
		if(a>=c){
			return a;
		}
	}
	if(b>=a){
		if(b>=c){
			return b;
		}
	}
	if(c>=a){
		if(c>=b){
			return c;
		}
	}
}
long long ans(int deep,int club,int n,int wei){
	if(deep==n){
		return 0;
	}
	if(date[wei][club]<n/2){
		date[wei][club]++;
		return maxx(k[deep][club]+ans(deep+1,0,n,wei),k[deep][club]+ans(deep+1,1,n,wei),k[deep][club]+ans(deep+1,2,n,wei));
	}
	else{
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int a=10,b=13,c=12;
	for(int w=0;w<t;w++){
		int n;
		cin>>n;
		int l=n/2;
		for(int i=0;i<n;i++){
			cin>>k[i][0]>>k[i][1]>>k[i][2];
		}
		cout<<maxx(ans(0,0,n,w),ans(0,1,n,w),ans(0,2,n,w))<<endl;
	}
	return 0;
}
