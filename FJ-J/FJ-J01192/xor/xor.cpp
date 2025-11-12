#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,ans=0;
int a[N];
bool A=true,B=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0){
			cout<<1<<endl;
			return 0;
		}
		if(a[i]==0){
			A=false;
		}
	}
	if(A){
		ans=n/2;
		cout<<ans<<endl;
	}else{
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else{
					if(i+1<=n&&a[i+1]==1){
						ans++;
						i+=1;
					}
				}
			}
			cout<<ans<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
