#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
    int snr=1;
    int h=1,l=1,base=1;
    if(a[1]==a1){
    	cout<<1<<" "<<1;
    	return 0;
	}
	while(1){
		if(h==n&&(l%2==1)){
			l++;
			base=-1;
		}
		else if(h==1&&(l%2==0)){
			l++;
			base=1;
		}
		else h+=base;
		snr++;
		if(a[snr]==a1){
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}
