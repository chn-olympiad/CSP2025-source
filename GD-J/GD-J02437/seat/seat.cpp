#include<bits/stdc++.h> 
using namespace std;
long long n,m,z=0,v,s,t=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin >> a[z++];
	}v=a[0];
	for(int i=0;i<n*m;i++){
		if(v<=a[i]){
			t++;
		}
    }v=t;s=v/n;
	if(v%n==0){
		cout << s << " ";
		if(s%2==0){
			cout << 1;
		}else{
			cout << n;
		}
	}else{
		cout << s+1 << " ";
		if((s+1)%2==0){
			cout << (s+1)*n-v+1;
		}else{
			cout << v%n;
		}
	} 
	return 0;
}
