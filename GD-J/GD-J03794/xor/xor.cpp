#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k;
int mp[N]={-1};
int f[N];
bool tof=true;
bool tof1=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>mp[i];
    	f[i]=mp[i];
    	if(mp[i]!=1) tof=false;
    	if(mp[i]>1) tof1=false;
	}
	if(tof==true){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
	}else if(tof1==true){
		int zeron=0,onen=0;
		for(int i=1;i<=n;i++){
			if(mp[i]==0) zeron++;
			if(mp[i]==1) onen++;
		}
		if(k==1) cout<<onen;
		else if(k==0) cout<<zeron+(onen/2);
		else cout<<0; 
	}else{
		int ans=0;
		int x=1;
		for(int i=1;i<=n;i++){
			if(mp[i]==k){
				ans++;
				x=i+1;
			}else{
				for(int j=x;j<i;j++){
					f[j]=f[j]^mp[i];
					if(f[j]==k){
						x=i+1;
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
