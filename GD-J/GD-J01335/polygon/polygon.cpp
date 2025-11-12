#include<cstdio> 
#include<iostream>
using namespace std;
const int N=5010,Mod=998244353;
int n;
long long cnt;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i+2<=n;i++){
		long long Max=-1;
		long long sum=0;
		sum+=a[i];
		if(a[i]>Max)Max=a[i];
		sum+=a[i+1];
		if(a[i+1]>Max)Max=a[i+1];
		sum+=a[i+2];
		if(a[i+2]>Max)Max=a[i+2];
		
		if(sum>Max*2){
			cnt++;
		}
		
		for(int j=1;j+i+2<=n;j++){
			sum+=a[j+i+2];
			if(a[j+i+2]>Max){
				Max=a[j+i+2];
			}
			if(sum>Max*2){
				cnt++;
			}
		}
	}
	cout<<cnt%Mod;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
