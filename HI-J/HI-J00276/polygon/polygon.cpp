#include<bits/stdc++.h>
using namespace std;
int cj[501],ans,minn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cj[i];
	}
	for(int i=7;i<1<<n;i++){
	int len=0,mlen=0,p=0;
		for(int j=0;j<n;j++) if((i>>j)%2) len+=cj[j],mlen=max(mlen,cj[j]),p++;
		if(p<3) continue;
		if(len<=mlen*2) continue;
		ans++;
	}
	cout<<ans;
	return 0;
}
