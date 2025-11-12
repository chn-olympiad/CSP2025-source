#include<bits/stdc++.h>
using namespace std;
struct rep{string s1,s2;}a[200010];
string x,y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n,q,cnt,lx,t1,t2;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>a[i].s1>>a[i].s2;
	for(int i = 1;i<=q;i++){
		cin>>x>>y;
		lx = x.size();
		cnt = 0;
		for(int j = 1;j<=n;j++)
			for(int k = 0;k<lx;k++){
				t1 = x.find(a[j].s1,k),t2 = y.find(a[j].s2,k);
				if(t1==t2&&t1!=-1&&t2!=-1)cnt++;
			}
		cout<<cnt<<'\n';
	}
	return 0;
}

