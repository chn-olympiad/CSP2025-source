#include<bits/stdc++.h>
using namespace std;
long long n,m,top=1,ans1,ans2,score,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--,top++){
        if(a[i]==score){
            break;
        }
	}
	ans1=(top%n==0)?(top/n):(top/n+1);
	ans2=(ans1%2==1)?(top-(ans1-1)*n):(n-(top-(ans1-1)*n)+1);
    cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}
