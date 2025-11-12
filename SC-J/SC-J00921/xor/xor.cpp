#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],da,l,r,v,f;
bool a1[5000005];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a1[j]!=0)continue;
			f=0;
			da=a[j]; 
//			cout<<da<<endl;
//			cout<<i<<" "<<j<<" "<<v<<endl;
			for(int o=j+1;o<j+i;o++){
				da=da^a[o];
				if(o>n){
					f=1;
					break;
				}
				if(a1[o]!=0){
					f=1;
					break;
				}	
//				cout<<1111111111<<endl;
			}
			if(f==1)continue;
//			if(j==1&&i==1){
//				cout<<da<<" "<<a[j]<<endl<<endl;
//			}
			if(da==k){
				v++;
				for(int c=j;c<j+i;c++){
					a1[c]=1;
				}
//				cout<<i<<" "<<j<<" "<<j+i-1<<endl;
			}
			
			da=0;
		}
	}
	cout<<v<<endl;
	return 0;
}