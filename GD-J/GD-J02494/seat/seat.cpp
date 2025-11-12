#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+1+n*m,cnt);
	int t;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			t=i;
			break;
		}
	}
	int x=1,y=1;
	bool c=0;
//	cout<<t<<'\n';
	t--;
	while(t--){
		if(y==m&&c==0){
			x++;
			y=m;
			c=1;
			continue;
		}
		else if(y==1&&c==1){
			x++;
			y=1;
			c=0;
			continue;
		}if(c==1){
			y--;
		}else{
			y++;
		}
		
	}
	cout<<x<<' '<<y;
	return 0;
} 
