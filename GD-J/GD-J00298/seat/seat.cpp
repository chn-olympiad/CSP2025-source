#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],id,ls=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m*n;i+=n){ 
		ls++;
		if(a[i]>=id&&id>=a[i+n]){
			int hs=0;
			if(ls%2==0){
//				hs=n;
				for(int j=i+n-1;j>=i;j--){
					hs++;
					if(a[j]==id){
						cout<<ls<<" "<<hs;
						return 0;
					}
//					cout<<a[j]<<" ";
				}
			}else{
				for(int j=i;j<=i+n-1;j++){
					hs++;
					if(a[j]==id){
						cout<<ls<<" "<<hs;
						return 0;
					}
//					cout<<a[j]<<" ";
				}
			}
//			cout<<endl;
		}
	}
	return 0;
}	

