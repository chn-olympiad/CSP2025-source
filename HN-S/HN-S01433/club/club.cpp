#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int m;
int n;
struct node {
	int a;
	int b;
	int c;
}t[N];
bool cmp(node x,node y){
	return x.a<y.a;
}
bool cmp2(node x,node y){
	return x.b<y.b;
}
bool cmp3(node x,node y){
	return x.c<y.c;
}
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n;
		memset(t,0,sizeof(t));
		for(int j=1;j<=n;j++){			
			cin>>t[j].a>>t[j].b>>t[j].c;
			sum+=max(max(t[j].a,t[j].b),t[j].c);
		}
		cout<<sum<<"\n";
		
	}
	return 0;
}
