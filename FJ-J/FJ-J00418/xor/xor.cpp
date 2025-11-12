#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,l,p,sum;
int a[N],b[N][5];
int e[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1000){
	for(int i=1;i<=n;i++){
		p=a[i];
		if(p==k){
				b[++l][1]=i;
				b[l][2]=i;
			}
		for(int j=i+1;j<=n;j++){
			p^=a[j];
			if(p==k){
				b[++l][1]=i;
				b[l][2]=j;
			}
		}
	}
	for(int i=1;i<=l;i++){
		int o=0;
		for(int j=i+1;j<=l+1;j++){
			o=0;
			if((b[i][1]>=b[j][1]&&b[i][1]<=b[j][2])||(b[i][2]>=b[j][1]&&b[i][2]<=b[j][2])||(b[j][1]>=b[i][1]&&b[j][1]<=b[i][2])||(b[j][2]>=b[i][1]&&b[j][2]<=b[i][2])){
				if(e[i]==1){
				o=1;
				}else {
				o=0;
				e[j]=1;}
				break;
			}else{
				o=1;
			}
			
		}
		sum+=o;
	}	
	}
	cout<<sum;
	return 0;
} 
