#include<bits/stdc++.h>
using namespace std;
int s[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a=1,b=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(s[1]>s[i]){
			b++;
			if(b>m){
				b--;
				a++;
			}
		}	
	}
	cout<<a<<" "<<b;
	return 0;
}
