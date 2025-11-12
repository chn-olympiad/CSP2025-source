#include <bits/stdc++.h>
using namespace std;
bool cmp (int a,int b){
	return a>b;
	}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,w,m,a1,a[300];
	cin>>n>>m;
	for (int i=1;i<=n*m;++i){
		cin>>a[i];
		if (i==1)
		a1=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;++i){
	if (a1==a[i]){
		w=i;
		break;
		}
	}
	int beyond=1,x=1,y=1,j=1;
	while(1){
		if (beyond==w){
			cout<<y<<" "<<x<<endl;
			break;
			}
		x+=j;
		if (x>n){
			y++;
			j*=-1;
			x+=j;
			}
			if (x<1){
			y++;
			j*=-1;
			x+=j;
		}
		beyond++;
	}	
	return 0;
	}
