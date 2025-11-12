#include <bits/stdc++.h>
using namespace std;
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,comp);
	int l=1,h=1;
	int ans=1;
	if(a[1]==t){
		cout<<1<<" "<<1;
		return 0;
	}
	while(l>=1&&l<=m || h<=n&&h>=1){
		
		while(h+1<=n&&h+1>=1){	
			h++;
			ans++;
			if(a[ans]==t){
				cout<<l<<" "<<h;
				return 0;
			}
		}
		if(l+1<=m){
			l++;
			ans++;
			if(a[ans]==t){
				cout<<l<<" "<<h;
				return 0;
			}
		}
		while(h-1<=n&&h-1>=1){	
			h--;
			ans++;
			if(a[ans]==t){
				cout<<l<<" "<<h;
				return 0;
			}
		}
		if(l+1<=m){
			l++;
			ans++;
			if(a[ans]==t){
				cout<<l<<" "<<h;
				return 0;
			}
		}
	}
	return 0;
}
