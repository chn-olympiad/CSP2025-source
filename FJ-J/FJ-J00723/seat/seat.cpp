#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int a,num;
}s[110];
bool cmp(Node x,Node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>s[i].a;
		s[i].num=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(s[i].num==1){
			if((i-1)/n & 1){
				cout<<(i-1)/n+1<<" "<<n-((i-1)%n);
			}
			else{
				cout<<(i-1)/n+1<<" "<<(i-1)%n+1;
			}
			break;
		}
	}
	return 0;
}
