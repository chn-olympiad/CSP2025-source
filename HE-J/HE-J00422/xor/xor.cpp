#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[10005],x,ant=0,b[10005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=a[i];
		if(x==k&&b[i]==0){
			b[i]=1;
			ant++;
		}
		if(a[i]==0){
			continue;
			}
		for(int j=i+1;j<=n;j++){
			x=x^a[j];
			if(a[j]==0||b[j]==1){
					continue;
				}
			if(x==k&&b[j]==0){
			  ant++;	
			  for(int q=i;q<=j;q++){
			  	b[q]=1;
			  }
			}
		}
	}
	cout<<ant;
	return 0;
}
