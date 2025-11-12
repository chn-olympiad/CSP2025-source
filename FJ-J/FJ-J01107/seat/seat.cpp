#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,m,r,a[N],b;
bool cmp(int b,int c){
	if(b>c) return 1;
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == r){
			b=i;
			break;
		}
	}
//	cout<<b<<endl;
	if(b%n == 0){
		if((b/n)%2 == 0){
			cout<<b/n<<' '<<1;
		}else{
			cout<<b/n<<' '<<n;
		} 
	}else{
		if((b/n)%2 == 0){
			cout<<(b/n)+1<<' '<<b%n;
		}else{
			cout<<(b/n)+1<<' '<<n-(b%n)+1;
		}
	}
	return 0;
}
