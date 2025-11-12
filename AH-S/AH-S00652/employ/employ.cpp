#include<bits/stdc++.h>
using namespace std;
int a[114514][3],f1[57257],f2[57257],f3[57257];
vector<int>c,w;
void run(){
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	int n;int Max=-1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=1;j--){
			f1[j]=max(f1[j],f1[j-1]+a[i][1]);
			f2[j]=max(f2[j],f2[j-1]+a[i][2]);
			f3[j]=max(f3[j],f3[j-1]+a[i][3]);
		}
		for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			int l=n-j-k;
			if(l<0||l>n/2)continue;
			Max=max(f1[j]+f2[k]+f3[l],Max);
		}
	}
	}
	cout<<Max<<"\n";
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int m,n,Max=0;
	cin>>m>>n;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++){
		int b;
		cin>>b;
		Max=max(Max,b);
	}
	cout<<Max<<"\n";
	return 0 ;
}
