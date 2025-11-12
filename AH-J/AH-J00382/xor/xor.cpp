#include<iostream>
using namespace std;
int n,k,a[500010];
void work1(){
	cout<<n<<endl;
}
void work2(){
	int ans=0;
	if(k==0){
		int x=0;
		for(int i=1;i<=n;i++){
			x=x^a[i];
			if(x==k) ans++,x=0;
		}
	}
	else{
		int x=0;
		for(int i=1;i<=n;i++){
			x=x^a[i];
			if(x==k) ans++,x=0;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int u=1,v=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){ cin>>a[i],u*=a[i];if(a[i]>1) v--;}
	if(k==0 && u){ work1(); return 0;}
	if(k<=1 && v){ work2(); return 0;}
	int ans=0,x=0;
	for(int i=1;i<=n;i++){
		x=x^a[i];
		if(x==k) ans++,x=0;
	}
	cout<<ans<<endl;
	return 0;
}
