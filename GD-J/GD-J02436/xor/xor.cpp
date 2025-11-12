#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long a[10005];
int b[1005];
void nu(int x){
	for(int i=20;i>=0;i--){
		if(x-pow(2,i)>=0){
			x-=pow(2,i);
			if(b[i]==1){
				b[i]=0;
			}else{
				b[i]=1;
			}
		}else if(x-pow(2,i)<0){
			if(b[i]==0){
				b[i]=0;
			}else{
				b[i]=1;
			}
		}
	}
	cout<<endl;
}
void num(int x,int y){
//	if(x==y){
//		if(a[x]==k){
//			ans++;
//		}
//		return; 
//	}
	long long t=a[x];
	for(int i=20;i>=0;i--){
		if(t-pow(2,i)>=0){
			t-=pow(2,i);
			b[i]=1;
		}else{
			b[i]=0;
		}
	}
	for(int i=x+1;i<=y;i++){
		nu(a[i]);
	}
	long long o=0;
	for(int i=0;i<=20;i++){
		
		if(b[i]==1){
			o+=pow(2,i);	
		}
	}
	if(o==k){
		ans++;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			memset(b,0,sizeof(b));
			num(i,j);
		}
	}
	cout<<ans;
	


	
	
	return 0;
}
