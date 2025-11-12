#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=150;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	int a_1;
	scanf("%d",&a_1);
	
	for(int i=1;i<n*m;i++)scanf("%d",&a[i]);
	a[n*m]=a_1;
	
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	
	int r=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a_1){
			r=i;
			break;
		}
	}
	
	int t=r/n;
	
	if(r%n==0){
		if((r/n)%2==0) cout<<r/n<<" "<<1;
		else cout<<r/n<<" "<<n;
		
		return 0;
	} else t++;
	
	if(t==0) cout<<1<<" "<<r;
	else {
		if(t%2==0){
			cout<<t<<" "<<n+1-r%n;
		}else{
			cout<<t<<" "<<r%n;
		}
	}
	return 0;
}
