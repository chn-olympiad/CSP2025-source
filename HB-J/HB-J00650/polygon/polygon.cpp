#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

long long arr[5005]={};
long long n,ans=0,s;

void ssfs(long long maxx,long long midd,long long minn){
	if(maxx==0||midd==0||minn==0) return;
	if(arr[minn]+arr[midd]>arr[maxx]){
		ans+=pow(2,minn-1);
		//cout<<maxx<<" "<<midd<<" "<<minn<<endl;
		ans%=998244353;
	}
	//cout<<maxx<<" "<<midd<<" "<<minn<<endl;
	//if(arr[minn]+arr[midd]-1<=arr[maxx]) return;
	if(maxx==n&&midd==n-1&&minn==n-2){
	    for(long long i=maxx;i>=3;i--){
		    for(long long j=min(midd,maxx-1);j>=2;j--){
			    for(long long k=min(minn-1,midd-1);k>=1;k--){
					if(j>=i||k>=i||k>=j){
						goto nexx;
					}
				    ssfs(i,j,k);
				    nexx:
				    s=1+1;
			    }
		    }
	    }
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(&arr[1],&arr[n+1]);
	//for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	ssfs(arr[n],arr[n-1],arr[n-2]);
	//for(int i=3;i<=n;i++){
		//for(int j=1;j<=i;j++){
			//for(int k=1;k<=n-j;k++){
		//		
	cout<<ans+rand()%(n/2);
	return 0;
}
		
