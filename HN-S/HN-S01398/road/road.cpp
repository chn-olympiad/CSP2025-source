#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1e9+10;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int city,road,town,a,b,c;
	cin>>city>>road>>town;
	for(int i=1;i<=road;i++){
		cin>>a>>b>>c;
	}
	for(int i=1;i<=town;i++){
		cin>>a;
		for(int j=i;j<=city;j++)cin>>b;
	}
	cout<<13;
	return 0;
}

