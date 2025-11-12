#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[10010],ans1,ans2,cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){ 
			cnt=i;
			break;
		}
//		cnt=i;
	}
	ans1=int(ceil(cnt*1.0/n));
	if(ans1%2) ans2=cnt-(ans1-1)*n;
	else ans2=ans1*n-cnt+1;
	cout<<ans1<<" "<<ans2<<"\n";
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

















