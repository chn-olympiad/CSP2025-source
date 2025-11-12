#include<iostream>
using namespace std;
int a[500010],addn[500010];
bool e;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=0,r=0,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)addn[i]=a[i];
		else addn[i]=addn[i-1]^a[i];
	}
//	for(int i=0;i<n;i++)cout<<addn[i]<<" ";
//	cout<<endl;
	while(l<n){
//		cout<<l<<" "<<r<<" ";
		if(!e){
			if(addn[r]==k){
				ans++;
				l=r;
//				cout<<k<<endl;
				e=1;
			}else{
//				cout<<addn[r]<<endl;
			}
		}else if((addn[l]^addn[r])==k){
			ans++;
			l=r;
//			cout<<k<<endl;
		}else{
//			cout<<(addn[l]^addn[r])<<endl;
		}
		if(r+1>=n)
			l++;
		else
			r++;
	}
	cout<<ans;
	return 0;
}
