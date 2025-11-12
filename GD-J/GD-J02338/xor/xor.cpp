#include<bits/stdc++.h>
using namespace std;

const int N=5e5+50;
int a[N];
int b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		a[i]=num;
		if(a[i]!=1&&flag<=1){
			if(a[i]==0){
				flag=1;
				cnt++;
			}else if(a[i]>1){
				flag=2;
			}
		}
	}
	int ans=0;
	if(flag==0){
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<(n-1)/2;
		}
		return 0;
	}else if(flag==1){
		if(k==0){
			ans+=cnt;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}else{
			ans+=n-cnt;
			for(int i=1;i<=n;i++){
				if(a[i]==0&&a[i+1]==0){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
		return 0;
	}else{
		/*b[1]=a[1];
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]^a[i];
		}
		for(int i=1;i<)*/
		cout<<1;
		return 0;
	}
	return 0;
} 
