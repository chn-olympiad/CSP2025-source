#include<bits/stdc++.h>
using namespace std;
const int N=301;
long long n,m,k,ki,cnt;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.cout","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i])ki=i;
	}
	//cout<<ki<<endl;
	while(ki>=n){
		ki-=n;
		cnt++;
	}
	//cout<<ki<<endl;
	if(cnt%2==0){//
		if(ki!=0){
			cout<<cnt+1<<" "<<ki<<endl;
		}else{
			cout<<cnt<<" "<<1<<endl;
		}
	}else{
		if(ki!=0){
			cout<<cnt+1<<" "<<n-ki+1<<endl;
		}else{
			cout<<cnt<<" "<<n<<endl;
		}
	}
}

