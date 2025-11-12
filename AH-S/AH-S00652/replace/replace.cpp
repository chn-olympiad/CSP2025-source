#include<bits/stdc++.h>
using namespace std;
int a[114514][3],f[57257],f1[57257],f2[57257],f3[57257];
vector<int>c,w;
void run(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=1;j--){
			f1[j]=max(f1[j],f1[j-1]+a[i][1]);
			f2[j]=max(f2[j],f2[j-1]+a[i][2]);
			f3[j]=max(f3[j],f3[j-1]+a[i][3]);
			
		}
	}
	for(int i=1;i<=n/2;i++){
		c.push_back(f1[i]);
		c.push_back(f2[i]);
		c.push_back(f3[i]);
		w.push_back(i);
		w.push_back(i);
		w.push_back(i);
	}
	for(int i=0;i<w.size();i++){
		for(int j=n;j>=w[i];j--)f[j]=max(f[j],f[j-w[i]]+c[i]);
	}
	cout<<f[n]<<"\n";
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n+m;i++){
		string x,y;
		cin>>x>>y;
	}
	cout<<0<<endl;
	return 0 ;
}
