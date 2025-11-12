#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,a[500005],ans,temp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			temp=0;
			continue;
		}
		else{
			temp^=a[i];
			if(temp==k) {
				ans++;
				temp=0;	
			}
		} 
	}
	cout<<ans;
	return 0;
}