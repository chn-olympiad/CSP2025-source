#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,a[105],R,fx=0;
bool cmp(int sddl,int otto){
	return sddl>otto;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		if(fx==0){
			if(y==n){
				fx=1;
				x++;
			}
			else y++;
		}
		else{
			if(y==1){
				fx=0;
				x++;
			}
			else y--;
		}
	}
	return 0;
}
