#include<bits\stdc++.h>
using namespace std;
int n,k,a[500005],nr[500005],rlr,anss;
bool bb1,bb2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			bb1=1;
		}if(a[i]>1)bb2=1;
	}if(bb1==0 and k==0){
		cout<<n/2;
		return 0;
	}else if(bb2==0 and k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)anss++;
		cout<<anss;
		return 0;
	}else if(bb2==0 and k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)anss++;
			else{
				if(a[i]==1 and a[i+1]==1){
					anss++;
					i++;
				}
			}
		}cout<<anss;
		return 0;
	}for(int i=1;i<=n;i++){
		int h=0;
		nr[i]=-1;
		for(int j=i;j<=n;j++){
			h^=a[j];
			if(h==k){
				nr[i]=j;
				break;
			}
		}
	}for(int i=1;i<=n;i++){
		if(nr[i]==-1)continue;
		if(i>rlr){
			rlr=nr[i];
			anss++;
		}else{
			if(nr[i]<=rlr){
				rlr=nr[i];
			}
		}
	}cout<<anss;
	return 0;
} 
