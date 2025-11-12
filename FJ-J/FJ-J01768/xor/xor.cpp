#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;i++)
#define pr(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=5e5+1;
int n,k,a[N],xorsum[N],ans;
bool vis[N]={0},t;
int main(){
	freopen("xor.in",r,stdin);
	freopen("xor.out",w,stdout);
	cin>>n>>k;
	rp(i,1,n)cin>>a[i],xorsum[i]=xorsum[i-1]^a[i];
	rp(i,1,n)
		rp(j,i,n)
			if(xorsum[j]-xorsum[i-1]==k){
				t=1;
				rp(k,i,j){
					if(!vis[k])vis[k]=1;
					else{t=0;break;}
				}
				if(t)ans++;
			}
	cout<<ans;
	return 0;
}

//I love ¡é¡é¡ê
//ÓÚ10:36Íê³É 
