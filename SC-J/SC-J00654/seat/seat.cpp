#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,id;
}s[123];
bool cmp(st axa,st byb){
	return axa.a>byb.a;
}
int n,m,cnt=0;
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m ;i++){
		cin>>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+1+n*m,cmp);
	int x=1,y=1;
	int d[]={-1,1};
	for(int c=1;c<=n*m;c++,y+=d[x%2]){
		if(y>n){
			y=n;
			x++;
		}
		if(y<1){
			y=1;
			x++;
		}
		if(s[c].id==1){
			cout<<x<<' '<<y<<'\n';
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}