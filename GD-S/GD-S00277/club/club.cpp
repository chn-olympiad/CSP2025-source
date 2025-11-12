#include<bits/stdc++.h>
using namespace std;
struct h{
	int a,b,c;
}l[100005];
int cmp(h a,h b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int ans=0;
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
		}
		sort(l+1,l+m+1,cmp);
		for(int i=1;i<=m/2;i++){
			ans+=l[i].a;
		}
		cout<<ans;
	}
} 
