#include<bits/stdc++.h>
using namespace std;
long long n,k,a[50050],ans,l=1,max1,min1=2147483647;
void tj(int l,int r){
	int sum=0,now=a[l],i=l,j=i;
	if(l>r)return ;
	while(i<=j&&j<=r){
		if(now==k){
			sum++;
			now^=a[i];
			i++;
		}else if(now>k){
			now^=a[i];
			i++;
		}else{
			now^=a[++j];
		}
	}
	ans+=sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		min1=min(min1,a[i]);
		if(a[i]==k){
			tj(l,i-1);
			ans++;
			l=i+1;
		}
	}
	if(max1==1&&min1==1){
		cout<<((n-1)+((n-1)%2))*(((n-1)-((n-1)%2))/2+1)/2;
	}else if(min1==0&&max1==1){
		if(k==1){
			
		}else if(k==0){
			
		}
	}else{
		tj(l,n);
		cout<<ans;
	}
	
	//bukeyizongsiling,pianfen
	return 0;
}
