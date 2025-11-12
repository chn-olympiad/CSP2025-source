#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long n,m,a[N],cnt=0,b[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	cnt=a[1];
	sort(b+1,b+1+n*m,cmp);
	long long w=0;
	for(int i=1;i<=n*m;i++){
		if(b[i]==cnt){
			w=i;
			break;
		}
	}
	if(w%n==0){
		cout<<w/n<<' ';
		if(w/n%2==0) cout<<1;
		else cout<<n;
		return 0;
	}
	if(w/n%2==0){
		cout<<ceil(w*1.0/n)<<' '<<w-(w/n)*n;
	}else{
		cout<<ceil(w*1.0/n)<<' '<<n-(w-floor(1.0*w/n)*n)+1;
	}
	return 0;
}