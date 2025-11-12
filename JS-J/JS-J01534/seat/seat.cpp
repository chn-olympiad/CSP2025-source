#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int n,m,a[MAXN],ccf=-1,pos=-1;
bool cmp(int q,int p){
	return q>p;
}
void work(int x){
	int bye=x/n+(x%n!=0);
	int lyoi=x%n;
	if(lyoi==0) lyoi=n;
	//cout<<bye<<" "<<lyoi<<endl;
	if(bye%2==1) cout<<bye<<" "<<lyoi<<endl;
	else cout<<bye<<" "<<n-lyoi+1<<endl;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	ccf=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
		if(ccf==a[i]){
			pos=i;
			break;
		}
	work(pos);
	return 0;
}
