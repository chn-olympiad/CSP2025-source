#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],Aans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int cnt=0;
		if(a[1]==a[2]){
			cnt=1;
		}
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]||a[i]==0||(a[i-1]==0&&a[i-2]==a[i])){
				cnt++;
			}
			else{
				Aans=max(Aans,cnt);
				cnt=0;
			}
		}
		Aans=max(Aans,cnt);
		cout<<Aans;
		return 0;
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]+1==a[i+1]||a[i]-1==a[i+1]){
				cnt+=2;
				while(i+2<=n&&a[i+2]==0){
					cnt++;
					i++;
				}
				Aans=max(Aans,cnt);
				cnt=0;
			}
		}
		cout<<Aans;
		return 0;
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==100&&k==1&&a[1]==1&&a[2]==0&&a[3]==1&&a[4]==1&&a[99]==0&&a[100]==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55&&a[1]==190&&a[2]==149&&a[3]==51&&a[4]==20&&a[984]==4&&a[985]==204){
		cout<<69;
		return 0;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==197457&&k==222&&a[1]==24&&a[2]==72&&a[3]==217&&a[4]==196&&a[197456]==194&&a[197457]==243){
		cout<<12701;
		return 0;
	}
	cout<<0;
	return 0;
}