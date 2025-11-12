#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,h=1,l=1,flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==k){
		cout<<1<<' '<<1;
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(h==n&&flag==0){
			l++;
			flag=1;
		}
		else{
			if(h==1&&flag==1){
				l++;
				flag=0;
			}
			else{
				if(flag==0)h++;
				else l++;
			}	
		}
		if(a[i]==k){
			cout<<l<<" "<<h;
			return 0;
		}
	}
}
