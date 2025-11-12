#include <bits/stdc++.h>
using namespace std;
int a[10005][4];
int b[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int p=1;p<=t;p++)
	{
		int bj1=1, bj2=1, bj3=1;
		int n, ans=0;
		cin >> n;
		bool q=true, w=true, e=true;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1]!=0)q=false;
			if(a[i][2]!=0)w=false;
			if(a[i][3]!=0)e=false;
		}
		if(q||w||e){
			if((q&&w)||(q&&e)||(w&&e)){
				for(int i=1;i<=n;i++)
				b[i]=max(a[i][1], max(a[i][2], a[i][3]));
				ans=0;
				for(int i=1;i<=n-1;i++)
				for(int j=i+1;j<=n;j++)
				if(b[i]<=b[j])swap(b[i], b[j]);
				for(int i=1;i<=n/2;i++)
				ans+=b[i];
				cout << ans << endl;
			}
		}else{
			if(n==2){
				int d11=0, d21=0;
				int d12=0, d22=0;
				d11=max(a[1][1], max(a[1][2], a[1][3]));
				d12=max(a[2][1], max(a[2][2], a[2][3]));
				int bj1, bj2, jg1, jg2, zz1, zz2;
				if(d11=a[1][1])bj1=1;
				if(d11=a[1][2])bj1=2;
				if(d11=a[1][3])bj1=3;
				if(d12=a[2][1])bj2=1;
				if(d12=a[2][2])bj2=2;
				if(d12=a[2][3])bj2=3;
				if(bj1==1)d21=max(a[1][2], a[1][3]);
				if(bj1==2)d21=max(a[1][1], a[1][3]);
				if(bj1==3)d21=max(a[1][1], a[1][2]);
				if(bj2==1)d22=max(a[2][2], a[2][3]);
				if(bj2==2)d22=max(a[2][1], a[2][3]);
				if(bj2==3)d22=max(a[2][1], a[2][2]);
				jg1=d11+d22;
				jg2=d12+d21;
				zz1=d11+d12;
				zz2=max(jg1, jg2);
				if(bj1!=bj2)cout << zz1 << endl;
				if(bj1==bj2)cout << zz2 << endl;
			}
			else{
				ans=0;
				for(int j=1;j<=n;j++)
				ans+=max(a[j][1], max(a[j][2], a[j][3]));
				cout << ans << endl;
			}
		}
	}
	return 0;
}