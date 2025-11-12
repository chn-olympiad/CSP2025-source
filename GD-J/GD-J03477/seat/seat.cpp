#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,fenshu[110],wei[20][20],rfen,rpai,ac=1; 
bool cmp(int a,int b){
	if(a<b)return 0;
	return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>fenshu[i];
	    if(i==1)rfen=fenshu[i];
    }sort(fenshu+1,fenshu+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(fenshu[i]==rfen)rpai=i;
    for(int i=1;i<=m;i++){
    	if(i%2==0){
    		for(int j=n;j>=1;j--){			
    		    wei[j][i]=ac;
    		    ac++;
    		}
		}else{
			for(int j=1;j<=n;j++){			
    		    wei[j][i]=ac;
    		    ac++;
    		}
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        if(wei[i][j]==rpai)cout<<j<<" "<<i<<endl;
	return 0;
}
