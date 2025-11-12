#include<iostream>
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const int N=5e5+50;
ll n,k,aa[N],kf[32],o;
struct node{
	int k;
	int next,tnext;
}a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i].k;
	for(int i=1;i<=n;i++){
		if(a[i].k==0)o++;
	}int l=n-o;
	if(k==1){
		cout<<l;
	}else{
		l=0;
		for(int i=2;i<=n;i++){
			if(a[i].k==1&&a[i-1].k==1){
				l++,a[i].k=0;
			}
		}cout<<l+o;
	}
	return 0;
}
