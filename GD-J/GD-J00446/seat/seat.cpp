#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[210],r,l,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==R){
			r=i/n+1;
			if(i%n==0) r--;
			l=i%n;
			if(!l){
				if(!(i/n)&1) l=n;
				else l=1;
			}
			if((i/n)&1) l=n-l+1;
			cout<<r<<' '<<l<<'\n';
			break;
		}
}
/*
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
RP += INF
I am 593499!!
Wo Yao Shang GD Mi Huo Xing Wei Da Shang!!
Bu Que Ding Neng Fou Da Zhong Wen,
Suo Yi An Jiu Da Ying Wen.
Qiu Gei Ge J 1= S 1=
*/
