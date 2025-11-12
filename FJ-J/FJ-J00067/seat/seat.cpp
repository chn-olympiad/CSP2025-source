#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=0,xx,yy,tmp;
struct Node{
	int sum;
	int i;
}a[11111],s[110][110];
bool cmp(Node a,Node b){
	return a.sum>b.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<a[i].sum<<' ';
		if(a[i].i==1){
			tmp=i;
//			if(i%m==0){
//				xx=m;
//			}else{
//				xx=i%m;
//			}
//			yy=ceil(1.0*i/m);
		}
	}
//	cout<<endl;
	for(int i=1;i<=tmp;i++){
		if(x%2==1){
			y++;
			if(y>n){
				y=n;
				x++;
				if(x>m){
					break;
				}
			}
		}else{
			y--;
			if(y<1){
				y=1;
				x++;
				if(x>m){
					break;
				}
			}
		}
//		if(x==xx&&y==yy){
//			cout<<x<<' '<<y;
//			return 0;
//		}
	}
	cout<<x<<' '<<y;
//	cout<<endl<<tmp;
//	cout<<x<<' '<<y<<endl<<xx<<' '<<yy;
	return 0;
}
