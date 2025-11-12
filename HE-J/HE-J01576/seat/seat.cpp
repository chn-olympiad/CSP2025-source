#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int s[102];
bool ch(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int o=1;o<=n*m;o++){
		cin>>s[o];
	}cnt=s[1];
	int num=1,st=1,r=1,c=1;
	sort(s+1,s+(n*m)+1,ch);
	if(s[st]==cnt){
		cout<<c<<' '<<r;
		return 0;
	}
	st++;r+=num;
	while(1){
		if(s[st]==cnt){
			cout<<c<<' '<<r;
			return 0;
		}
		if(r==n){
			c++;num=-1;st++;
			if(s[st]==cnt){
				cout<<c<<' '<<r;
				return 0;
			}
		}
		else if(r==1){
			c++;num=1;st++;
			if(s[st]==cnt){
				cout<<c<<' '<<r;
				return 0;
			}
		}
		st++;r+=num;
	}
	return 0;
}
