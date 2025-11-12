#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct p{
	int a;
	int b;
	int c;
}cl[1000070];
bool cmp(p x,p y){
	if(x.a>y.a)return 1;
	else return 0;
}
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
		}
		sort(cl+1,cl+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=cl[i].a;
		}cout<<sum<<'\n';
	}
	
	return 0;
}