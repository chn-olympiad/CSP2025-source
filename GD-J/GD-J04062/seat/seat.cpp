#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],x,y,cnt=1;
bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> s[i];
		if(s[i]>s[1])cnt++;
	}
	x=(cnt-1)/n+1;
	if(x%2==1)y=(cnt-1)%n+1;
	else y=n+1-((cnt-1)%n+1);
	cout << x << ' ' << y <<endl;
	
	return 0;
}
