#include<bits/stdc++.h>
using namespace std;
bool b[10010];
bool pan(int l,int r){
	bool a=true;
	for(int i=l;i<=r;i++){
	 if(b[i]){
	 	a=false;
	 }
	 return a;
}
}
int main(){
//#Shang4Shan3Ruo6Shui4
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a[101010],c=1,n,m,k,sum=0,sum1=0;
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]==k){
		//	sum++;
		//	b[i]=1;
	//	}
	}
	
	while(c!=n+1){
		sum1=0;
		for(int j=c;j<=n;j++){
			sum1=a[j]^sum1;
			if(sum1==k&&pan(c,j)){
				sum++;
				for(int x=c;x<=j;x++){
					b[x]=1; 
				} 
				c=j+1;
				break;
			}
			if(j==n){
				c=n+1;
			}
		}
	
}

		
			cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
