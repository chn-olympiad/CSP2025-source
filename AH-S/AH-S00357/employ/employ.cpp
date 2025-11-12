#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","W",stdout);
    long long n,m,c[10010],ans=1,fail=0,g[10010],sum=0;
    string s;
    cin>>n>>m>>s;
    for(long long i=0;i<n;i++){
		cin>>c[i];
    }
for(int j=0;j<n;j++){
	fail=0;sum=0;
	for(long long i=0;i<n;i++){
	    g[i]=1;	
	}	 
    for(long long i=0;i<n;i++){
	    if(s[i]=='0'){
			fail++;
			g[i]=0;
		}
    }
    for(long long i=0;i<n;i++){
		if(g[i]!=0&&c[i]>fail){
		    sum++;
	    }
	}
	if(sum>=m)ans++;
}
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
