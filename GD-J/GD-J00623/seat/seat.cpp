#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>r;
    int nm=n*m;
    int ansx=1,ansy=1;
    for(int i=2,a;i<=nm;++i){
    	cin>>a;
    	if(a>r){
    		if(ansx&1){
    			if(ansy==n) ++ansx;
    			else ++ansy;
			}
			else{
				if(ansy==1) ++ansx;
				else --ansy;
			}
		}
	}
	cout<<ansx<<' '<<ansy;
    return 0;
}
