#include <iostream>
#include <algorithm>
using namespace std;
int a[101]; 
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int m=0,n=0;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	int h=n,l=1,cnt=0;
	for (int i=n*m;i>=1;i--){
		if ((cnt<=n && l==1 )|| (cnt<=n && l%2!=0))
			cnt++;
		if (cnt>n ||( cnt==1 && l>1)){
			
			l++;
		}
		if (cnt>n || (cnt<=n && l%2==0 && cnt!=0)){
			
			cnt--;
		}
		if (cnt==0)
			cnt=1;
		if (a[i]==s){
			cout<<l<<" "<<cnt;
		}
	}
	return 0;
	
	
}


