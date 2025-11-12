#include<bits/stdc++.h>
using namespace std;
int s[501],p[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,x,k=0,sum=0,j=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++ ){
		if(s[i]==1&&(p[i]-k)>=0){
		sum++;
		k=0;
		}else{
			k++;
		}
		if(sum==x){
			j++;
			break;
		}
	}
		for(int i=n-1;i>=1;i-- ){
		if(s[i]==1&&(p[i]-k)>=0){
		sum++;
		k=0;
		}else{
			k++;
		}
		if(sum==x){
			j++;
			break;
		}
	}cout<<j;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
