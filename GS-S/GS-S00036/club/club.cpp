#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a1,b1,c1;
	cin>>t;
	while(t--){
		int n,zh[3][2]={0},x=0;
		cin>>n;
		int a,b,c,d,xx=0;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			d=max(a,max(b,c));
			if(c==d&&zh[2][1]<n/2){
				zh[2][1]++;
				x+=c;
			}else if(b==d&&zh[1][1]<n/2-1){
				zh[1][1]++;
				x+=b;
			}else if(zh[0][1]<n/2){
				zh[0][1]++;
				x+=a;
			}else {
				if(zh[1][1]<n/2){
					zh[1][1]++;
					x+=b;
				}else if(zh[2][1]<n/2){
					zh[2][1]++;
					x+=c;
				}
			}
		}
		cout<<x<<"\n";
		x=0;
	}
	return 0;
}
