#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,r=0;
	cin>>n>>m;
	cin>>f;
	for(int i=1;i<n*m;i++){
		int s;
		cin>>s;
		if(s>f)r++;
	}if((r/n+1)%2==1)
		cout<<r/n+1<<' '<<r%n+1;
	else cout<<r/n+1<<' '<<m+1-(r%n+1);
	return 0;
}
