#include<bits/stdc++.h>
using namespace std;
struct xs{
		int cj;
		bool h;
	}a[100];
bool cmp(xs a,xs b){
		return a.cj>b.cj;
	}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		if(i==1)a[i].h=1;
		else a[i].h=0;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].h==1){
			int t;
			t=(i-1)/n;
			if((t+1)%2==0){
				if(i%n==0)cout<<(i-1)/n+1<<' '<<(t+1)%n+1;
				else cout<<(i-1)/n+1<<' '<<t%n+1;
				break;
			}else{
				cout<<i%n+1+(t+2)%n<<' '<<(t+1)%n+1;
				break;
			}
		}
	}	
	return 0;	
}
