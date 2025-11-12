#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int v,s = 0,a[10086],b[10086],c[10086],a1[10086],b1[10086],c1[10086];
		cin>>v;
		for(int j = 1;j <= v;j++){
			cin>>a[j]>>b[j]>>c[j];
			a1[a[j]] = j;
			b1[b[j]] = j;
			c1[c[j]] = j;
		}
		for(int j = 1;j <= v;j++){
			sort(a + 1,a + v + 1,greater<int>());
			s += a[1];
			a[1] = 0;
			b[a1[a[1]]] = 0;
			c[a1[a[1]]] = 0;
			sort(b + 1,b + v + 1,greater<int>());
			s += b[1];
			b[1] = 0;
			a[b1[b[1]]] = 0;
			c[b1[b[1]]] = 0;
			sort(c + 1,c + v + 1,greater<int>());
			s += c[1];
			c[1] = 0;
			a[c1[c[1]]] = 0;
			b[c1[c[1]]] = 0;
		}
		if(s % 2 == 1) cout<<s / 2<<"\n";
		else cout<<s<<"\n";
	}
	return 0;
}
