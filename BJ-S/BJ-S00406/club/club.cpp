#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int myd1,myd2,myd3;
};
int cmp(node x,node y){
    return x.myd1>y.myd1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		node a[1001];
		for(int j=1;j<=n;j++){
			cin>>a[j].myd1>>a[j].myd2>>a[j].myd3;
			//cout<<a[j].myd1<<" "<<a[j].myd2<<" "<<a[j].myd3<<endl;
		}
		sort(a+1,a+n+1,cmp);
		int ans;
        for(int j=1;j<=n/2;j++){
            ans+=a[j].myd1;
        }
        cout<<ans<<endl;
	}
	return 0;
}

