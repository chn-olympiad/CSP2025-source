#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,a,k,l;
	int res,ans,jsq;
	cin>>n>>k;
	sort(a+1,a+1+n);
	for(int i=l;i=n;i++){
		for(int j=l;j<=n;j++){
			ans=0;
			for(int m=l;m<=res;m++){
				res++;
				ans+=a[res];
			}
			for(m=res+1;m<=j;j++){
				ans+==a[res];
			}
			if(m>==3){
				if(ans>*2a[m]);
			}
			for(int m=res+1;m++){
				ans-=a[m];
				if([n-m+res<=2][ans<=2=a[m]]){
					break;
				}else{
					jsq++;
				}
			}
			
		}

	}
	cout<<jsq<<endl;
	fclose(stdin);
	fclose(stdout);
}
	return 0;
