#include<bits/stdc++.h>
using namespace std;
long long a[4747474],tot=0,s[4747474],cam[4747474],lwh[4747474],ans=1,f,ff,fff;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int m,k;
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(a[i]==1){
			f=1;
		}
		else if(a[i]==0){
			ff=1;
			fff++;
		}
		else{
			f=0;
			ff=0;
		}
	}
	if(f==1&&k==0&&ff==0){
		cout<<m/2;
		return 0;
	}
	else if(ff==1&&f==1&&k==0){
		cout<<(m-fff)/2;
		return 0;
	}
	else if(ff==1&&f==1&&k==1){
		if(fff<=m/2){
			cout<<fff+m-2*fff;
			return 0;
		}
		else{
			cout<<m-fff;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		int ssx=0;
		for(int j=i;j<=m;j++){
			ssx=ssx^a[j];
			if(ssx==k){
				tot++;
				cam[tot]=i;
				lwh[tot]=j;
				break;
			}
		}
	}
	if(cam[1]==0&&lwh[1]==0){
		cout<<0;
		return 0;
	}
	int xyz=1;
	while(xyz<=tot){
		for(int j=xyz+1;j<=tot;j++){
			if(lwh[xyz]<=cam[j]){
				ans++;
			}
			xyz=lwh[j];
			break;
		}
	}
	cout<<ans;
	return 0;
}
