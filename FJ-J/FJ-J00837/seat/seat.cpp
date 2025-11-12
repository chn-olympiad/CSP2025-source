#include<bits/stdc++.h> 
using namespace std;
int n,m,a[10005],c,cnt,z,d,k;

bool cmp(int x,int y){
	if(x<y) return false;
	return true;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){ 
			cin>>c;
		    a[++cnt]=c;
		}
	}
	z=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==z) d=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			k++;
			if(k==d){
				if(i%2==0){
					cout<<i<<" "<<n-j+1;
					return 0;
				}
				else{
					cout<<i<<" "<<j; 
					return 0;
				}
			}
		}
	}
	return 0;
}
