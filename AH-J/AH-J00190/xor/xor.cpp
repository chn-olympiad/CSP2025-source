#include<iostream>
using namespace std;
int n,k,a[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=0,y1=0,y2=0,t1,t2;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			x++;
		}
		if(a[i]==a[i-1]&&a[i]==1&&i-1!=t1){
			y1++;
			t1=i;
		}
		if(a[i]==a[i-1]&&a[i]==0&&i-1!=t2){
			y2++;
			t2=i;
		}
	}
	if(x==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cout<<x+y2;
	}else if(k==0){
		cout<<n-x+y1;
	}
	return 0;
}
