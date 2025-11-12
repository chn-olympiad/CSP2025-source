#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
long long n;
long long a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	long long asdf=0,anms=0;
	for(int	op=1;op<=n;op++){
		for(int i=op;i<=n;i++){
			asdf+=a[i];
			for(int j=i+1;j<=n;j++){
				if(asdf>a[j]){
					anms++;
				}
			}
			break;
		}
	}
	cout<<anms*3;
	return 0;
}
