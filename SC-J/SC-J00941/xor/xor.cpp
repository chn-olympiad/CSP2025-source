//1^1=0
//1^0=1;

#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;

int n,k;
int a[N];
int ans;


int fun(int x,int l,int r){
	if(x==1){
		int sum=0;
		for(int i=l;i<=r;i++){
			int m1=a[l],m2=a[i+1];
			for(int j=l+1;j<=i;j++)m1=m1^a[j];
			for(int j=i+2;j<=r;j++)m2=m2^a[j];
			if(m1==m2&&m1==k)sum=2;
			else if(m1==k||m2==k)sum=max(sum,1);
		}
		
		return sum;
	}else{
		int sum=0;
		for(int i=l;i<=r;i++){
			sum=max(sum,max(fun(x-1,l,i),fun(x-1,i+1,r)));
		}
		return sum;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	int xxxx1=1;
	
	for(int i=1;i<=n;i++){
		if(a[i]!=1)xxxx1=0;
	}
	
	if(xxxx1&&k==0)cout<<n<<endl;
	else{
		for(int i=1;i<=n;i++){
			ans=max(ans,fun(i,1,n));
		}
		cout<<ans;
	}
	
	return 0;
} 