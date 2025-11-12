#include<bits/stdc++.h>
using namespace std;
int a[5001];
int b[5001];
bool vit[5001];

int q[10001];
int sum;
int n;
bool cmp(int a,int b){
	return a<b;
}
void G(int s){
	if(s==n+1){
		bool y=false;
		int h=0;
		int ans=0;
		int l=0;
		for(int i=1;i<=n;i++){
			if(vit[i]){
				l++;
				
					h=a[i];
				
			//	cout<<a[i]<<" ";
				
				ans+=a[i];
			}
		}
	//	cout<<endl;
		if(l<3) return ;
		if(ans>2*h){
			sum++;
			sum%=998244353;
		}
		return ;
	}
	vit[s]=0;
	G(s+1);
	vit[s]=1;
	G(s+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	//	cout<<a[i]<<" ";
		
	}
//	cout<<endl;
	
 	if(b[n]<=n){
 		int sum1=0;
 		for(int i=1;i<=n;i++){
 			if(a[i]==1) sum1++;	
		}
		if(sum1<20){
			int l=(pow(2,sum1)-sum1-1-(sum1+1)*sum1/2);
		//	cout<<l%998244353;
			
		}
		int r=sum1%20;
		int x=sum1/20;
		long long sum2=1;
		int f=pow(2,20);
		for(int i=1;i<=x;i++){
			sum2*=f;
			sum2%=998244353;
		}
		sum2*=pow(2,r);
		sum2%=998244353;
		sum2=sum2-sum1-1-(sum1-1)*sum1/2;
		sum2%=998244353;
		//cout<<((pow(2,sum1)-sum1-1-(sum1+1)*sum1/2))<<endl;
		//printf("%d",(pow(2,sum1)-sum1-1-(sum1+1)*sum1/2)-((pow(2,sum1)-sum1-1-(sum1+1)*sum1/2)/998244353)*998244353);
	//	cout<<endl;
		cout<<sum2;
		return 0;
	}
	
	G(1); 
	cout<<sum%998244353;
	return 0;
}

