#include<bits/stdc++.h>
using namespace std;

int a[110],cnt,ans,lst;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[++cnt];
	lst=a[1];
	sort(a+1,a+cnt+1,greater<>());
	for(int i = 1;i <= m;i++){
		if(i&1){
			for(int j = 1;j <= n;j++){
				if(a[++ans]==lst) return cout<<i<<' '<<j<<'\n',0;
			}
		}else{
			for(int j = n;j;j--){
				if(a[++ans]==lst) return cout<<i<<' '<<j<<'\n',0;
			}
		}
	} 
	return 0;
}

