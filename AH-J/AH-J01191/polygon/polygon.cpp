#include<bits/stdc++.h>
using namespace std;
long long ans,n,qq[5005];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qq[i];
	}
		sort(qq+1,qq+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(((qq[1]+qq[2]+qq[3])-2*qq[3])>0){
				cout<<1;
				return 0;
		}
		else{
			cout<<0; 
			return 0;
			}
	}
	else if(n==4){
		if(((qq[1]+qq[2]+qq[3])-2*qq[3])>0) ans++;
		if(((qq[1]+qq[4]+qq[3])-2*qq[4])>0) ans++;
		if(((qq[4]+qq[2]+qq[3])-2*qq[4])>0) ans++;
		if(((qq[1]+qq[2]+qq[4])-2*qq[4])>0) ans++;
		if(((qq[1]+qq[2]+qq[3]+qq[4])-2*qq[4])>0) ans++;
		cout<<ans;
		return 0;
	}
	else if(n==5){
		if(((qq[1]+qq[2]+qq[3])-2*qq[3])>0) ans++;
		if(((qq[1]+qq[2]+qq[4])-2*qq[4])>0) ans++;
		if(((qq[1]+qq[2]+qq[5])-2*qq[5])>0) ans++;
		if(((qq[1]+qq[3]+qq[4])-2*qq[4])>0) ans++;
		if(((qq[1]+qq[3]+qq[5])-2*qq[5])>0) ans++;
		if(((qq[1]+qq[4]+qq[5])-2*qq[5])>0) ans++;
		if(((qq[2]+qq[3]+qq[4])-2*qq[4])>0) ans++;
		if(((qq[3]+qq[2]+qq[5])-2*qq[5])>0) ans++;
		if(((qq[4]+qq[2]+qq[5])-2*qq[5])>0) ans++;
		if(((qq[4]+qq[5]+qq[3])-2*qq[5])>0) ans++;
		if(((qq[1]+qq[2]+qq[3]+qq[4])-2*qq[4])>0) ans++;
		if(((qq[5]+qq[2]+qq[3]+qq[4])-2*qq[5])>0) ans++;
		if(((qq[5]+qq[2]+qq[3]+qq[1])-2*qq[5])>0) ans++;
		if(((qq[5]+qq[2]+qq[1]+qq[4])-2*qq[5])>0) ans++;
		if(((qq[5]+qq[1]+qq[3]+qq[4])-2*qq[5])>0) ans++;
		if(((qq[1]+qq[2]+qq[3]+qq[4]+qq[5])-2*qq[5])>0) ans++;
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}
