#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m,a[100086],ar,ls=1,hs=0,cnt=0,st=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			ar=a[i];
		}
	}
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(st==0 && ((cnt-1)%n!=0 || (cnt-1)==0)){
			hs++;
		}
		else if(st==1 && ((cnt-1)%n!=0 || (cnt-1)==0)){
			hs--;
		}
		if((cnt-1)%n==0 && (cnt-1)!=0){
			ls++;
			st=(st+1)%2;
		}
		if(a[i]==ar){
			cout<<ls<<" "<<hs;
			return 0;
		}
	}
    return 0;
}