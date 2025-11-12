#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=222;
int n,m,a[N],r,c,grade,idx;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	grade=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==grade){
			idx=i;
			break;
		}
	}
	c=(idx+n-1)/n;
	if(c%2)r=(idx-1)%n+1;
	else r=n-((idx-1)%n+1)+1;
	cout<<c<<" "<<r;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
