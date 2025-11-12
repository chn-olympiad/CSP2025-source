#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,t=0,t2=0; 
long long f(int x){
	long long ans=0,m=10;
	while(x!=0){
		ans+=x%2*m;
		m*=10;
		x/=2;
	}
	ans/=10;
	return ans;
} 
long long f2(long long x,long long y){
	long long ans=0,m=1;
	if(x>=y){
		while(x!=0){
			if(x%10+y%10!=2){
				ans+=(x%10+y%10)*m;
				m*=10;
				y/=10;
				x/=10;
			}
			else{
				m*=10;
				y/=10;
				x/=10;
			}
		}
	}
	else{
		while(y!=0){
			if(x%10+y%10!=2){
				ans+=(x%10+y%10)*m;
				m*=10;
				y/=10;
				x/=10;
			}
			else{
				m*=10;
				y/=10;
				x/=10;
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k=f(k);
	vector<int> a(n+10,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum=f2(sum,f(a[i]));
		if(sum==k){
			t++;
			sum=0;
		}
	}
	sum=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			sum=f2(sum,f(a[i]));
			if(sum==k){
				t2++;
				sum=0;
			}
		}
		if(t2>=t){
			t=t2;
		}
		t2=0;
	}
	cout<<t;
	return 0;
} 