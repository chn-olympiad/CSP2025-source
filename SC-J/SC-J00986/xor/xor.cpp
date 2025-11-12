#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int yh(int x,int y){
	if(x==y){
		return x;
	}
	long long cnt=0;
	int ab[100010],ba[100010],c[100010];
	int i=0;
	while(x!=0){
		ab[i]=x%2;
		i++;
		x/=2;
	}
	int j=0;
	while(y!=0){
		ba[j]=y%2;
		j++;
		y/=2;
	}
	for(int k=0;k<max(i,j);k++){
		if(ab[k]==ba[k]){
			c[k]=0;
		}else{
			c[k]=1;
		}
	}
	for(int k=0;k<max(i,j);k++){
		if(c[k]==1){
			cnt+=pow(2,k);
		}
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;){
		int f=0;
		for(int j=i;j<=n;j++){
		    a[i]=yh(a[i],a[j]);
		    if(a[i]==k){
		    	i=j+1;
		    	sum++;
		    	f=1;
		    	break;
			}
	    }
	    if(f==0){
	    	i++;
		}
	}
	cout<<sum;
	return 0;
} 