#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int a2[25];

int two(int x,int y){
	int i=0;
	while(!(x==0&&y==0)){
		if((x & y)>0)a2[i]=0;
		else a2[i]=1;
		x=x>>1;
		y=y>>1;
		
		i++;
	}
	int sum=0;
	for(int j=0;j<i;j++){
		sum+=a2[j]*pow(2, j);
	}
	return sum;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	int l=-1,r=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;	
		}
		else{
			l=i;
			int k1=a[i];
			for(int j=i+1;j<=n;j++){
				k1=two(k1,a[j]);
				if(k1==k){
					r=j;
					break;
				}
			}
			if(r!=-1){
				ans++;
				i=r;
			}
		}
	}
	cout<<ans;
	return 0;
}
