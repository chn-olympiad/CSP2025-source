#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m;
int mp[N];
int ans=1;
int num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>mp[i];
    	if(mp[i]>mp[1]) ans++;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				num++;
				if(ans==num){
					cout<<i<<" "<<j;
				}
			} 
		}else{
			for(int j=m;j>=1;j--){
				num++;
				if(ans==num){
					cout<<i<<" "<<j;
				}
			} 
		}
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

