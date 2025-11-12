#include<bits/stdc++.h>
using namespace std;
struct node{
	int indx,num;
} a[100005],b[100005],c[100005];
int main(){
	int t;
	cin >> t;
	for(int j=1;j<=t;j++){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
	}
}
