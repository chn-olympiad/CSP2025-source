#include<bits/stdc++.h>
using namespace std;
int n,r,g[510],z=1,j=1,cnt=0,h=0;
char a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>r;
    for(int i=1;i<=n;i++) cin>>a;
    for(int i=1;i<=n;i++) cin>>g[i];
    sort(g+1,g+1+n);
    j=2,h=1;
    while(j<=n&&cnt<r){
    	if(g[j]==g[j-1]){
    		h++;
		}else{
	        if(g[j]>=cnt){
	        	cnt++;
	        	z*=(h%998244353);
	        	z%=998244353;
			} 
		}
		j++;
    }
    if(cnt==0) z=0;
	cout<<z;
    return 0;
}
