#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,v[500005];
void qj(int i){
	for(int j=i;j<=n;j++){
		if(v[j]) continue;
		int x=a[i]^a[j];
		v[j]=1;
		if(x==k){
			ans++;
			return;	
		}
		else{
			for(int m=i;m<n;m++){
				v[m]=1;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]==k){
			ans++;
			v[i]=1;
		} 
	} 
	for(int i=0;i<n;i++){
		if(v[i]==1) break;
		v[i]=1;			
		qj(i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

