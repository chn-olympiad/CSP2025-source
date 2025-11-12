#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx2(ll m1[100005],ll m2[100005],ll m3[100005],int i){
	int a=max(m1[i]+m2[i+1],m1[i]+m3[i+1]);
	int b=max(m2[i]+m1[i+1],m2[i]+m3[i+1]);
	int c=max(m3[i]+m2[i+1],m3[i]+m1[i+1]);
	return max(max(a,b),c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ll n,m1[100005]={},m2[100005]={},m3[100005]={},sum=0,mx=sum;
		cin>>n;
		bool al1=1;
		for(int i=0;i<n;i++){
			cin>>m1[i]>>m2[i]>>m3[i];
			if(m2[i]+m3[i]!=0)al1=0;
		}
		if(al1){
			sort(m1,m1+n);
			for(int i=n-1;i>=n/2;i--)sum+=m1[i];
		}
		else{
			
			while(n>1){
				for(int i=0;i<n/2;i++){
					int x=mx2(m1,m2,m3,i*2);
					sum+=x;
				}
				mx=max(mx,sum);
				sum=0;
				n/=2;
				for(int i=0;i<n;i++){
					m1[i]=m1[i*2]+m1[i*2+1];
					m2[i]=m2[i*2]+m2[i*2+1];
					m3[i]=m3[i*2]+m3[i*2+1];
				}
				
			}
		}
		cout<<mx<<"\n";
	}
	return 0;
}
