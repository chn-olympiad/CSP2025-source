#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b,c;
	int id;
}a[100010];
bool cmp(node x,node y){
	return x.a>x.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0;
		sort(a,a+n,cmp);
		int j=0;
		while(k!=0){
			ans+=a[j].a;
			j++;
			k--;	
		}
		cout<<j<<endl;
	}
	return 0;
}
