#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
int a[500010];
//int getxor(int l,int r){
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flagA=0;
		if(a[i]!=1&&a[i]!=0)flagB=0;
	}
	if(flagA){//10pts
		cout<<n/2;
	}
	else if(flagB){//20pts
		if(k){
			int res=0;
			for(int i=1;i<=n;i++)res+=a[i];
			cout<<res;
		}
		else{
			int res=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)res++;
				else if(i+1<=n&&a[i+1]==1)res++,i++;
			}
			cout<<res;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			
//		}
//	}
	return 0;
}
