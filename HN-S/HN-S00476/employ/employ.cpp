#include<bits/stdc++.h>
using namespace std;
struct people{
	int id,c;
};
int n,m,ans=0;
char p[500];
struct people a[500];
bool cmp(struct people a,struct people b){
	return a.c <= b.c;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int mn = n;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++){
		cin>>a[i].c;
		a[i].id = i;
	}
	sort(a,a+n,cmp);
	int k=0;
	for(int i=0;i<n;i++){
		if(p[i] == '0'){
			int u = 2;
			for(int j=i;j>0;j--) u = u * 2;
			ans = ans + u;
			k++;
			mn--;
		}
		if(k > a[i].c){
			k++;
			mn--;
		}
	}
	if(mn < m){
		cout<<0<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
