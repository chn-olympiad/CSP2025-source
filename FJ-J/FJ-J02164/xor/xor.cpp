#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,k,ans=0;
long long a[N];
bool f[N];
bool check(int l,int r){
	int summ=a[l];
	for(int i=l+1;i<=r;i++){
		summ=summ^a[i];
	}
	if(summ==k){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freoprn("xor.out","w",stdout);
	memset(f,true,sizeof(f));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,true,sizeof(f));
		for(int j=n;j>=1;j--){
			if((f[i] && f[j]) && i<=j && a[i]!=0 && a[j]!=0){
				if(check(i,j)){
					for(int a=i;a<=j;a++){
						f[a]=false;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
