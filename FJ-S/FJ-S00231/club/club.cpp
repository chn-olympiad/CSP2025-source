#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int a[(int)(1e5+5)][3];
int f[205][205][2];
int A[(int)(1e5+5)];
int fteB[(int)(1e5+5)][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int n;
	while (t--){
		cin >> n;
		bool teA=true,teB=true;
		for (int i=1;i<=n;++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			A[i]=a[i][0];
			if (a[i][1]!=0) teA=false;
			if (a[i][2]!=0){teA=false;teB=false;}
		}
		if (teA){
			sort(A+1,A+n+1,greater<int>());
			int ansA=0;
			for (int i=1;i<=n/2;++i)
				ansA+=A[i];
			cout << ansA << endl;
			continue;
		}
		else if (teB){
			fteB[1][0]=a[1][0];fteB[0][0]=a[1][1];
			for (int i=2;i<=n;++i){
				for (int x=0;x<=min(n/2,i);++x){
					int y=i-x;
					if (y>n/2 or y<0) continue;
					fteB[x][1]=-0x3f3f3f3f;
					if (x>0) fteB[x][1]=max(fteB[x][1],fteB[x-1][0]+a[i][0]);
					if (y>0) fteB[x][1]=max(fteB[x][1],fteB[x][0]+a[i][1]);
				}
				for (int x=0;x<=min(n/2,i);++x)
					fteB[x][0]=fteB[x][1];
			} cout << fteB[n/2][0] << endl;
			continue;
		}
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				f[i][j][0]=0;
				f[i][j][1]=0;
			}
		}
		f[1][0][0]=a[1][0];f[0][1][0]=a[1][1];f[0][0][0]=a[1][2];
		for (int i=2;i<=n;++i){
			for (int x=0;x<=min(n/2,i);++x){
				for (int y=0;y<=min(n/2,i);++y){
					int z=i-x-y;
					if (z>n/2 or z<0) continue;
					f[x][y][1]=-0x3f3f3f3f;
					if (x>0) f[x][y][1]=max(f[x][y][1],f[x-1][y][0]+a[i][0]);
					if (y>0) f[x][y][1]=max(f[x][y][1],f[x][y-1][0]+a[i][1]);
					if (z>0) f[x][y][1]=max(f[x][y][1],f[x][y][0]+a[i][2]);
//					cout << "x " << x << " y " << y << " z " << z << " i " << i << " :" << f[x][y][0] << " ";
				} //cout << endl;
			} //cout << endl;
			for (int x=0;x<=min(n/2,i);++x){
				for (int y=0;y<=min(n/2,i);++y){
					f[x][y][0]=f[x][y][1];
//					cout << f[x][y][0] << " ";
				}
//				cout << endl;
			} //cout << endl;
		} int ans=-1;
		for (int x=0;x<=n/2;++x){
			for (int y=0;y<=n/2;++y){
				int z=n-x-y;
				if (z>n/2) continue;
				ans=max(ans,f[x][y][0]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;

int t;
int a[(int)(1e5+5)][2];
int blt[(int)(1e5+5)];
vector<int> v[2];
//int f[(int)(5e4+5)][(int)(5e4+5)];

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> t;
	int n;f[0][3]=1;
	while (t--){
		cin >> n;
		int ans=0,cnt0=0,cnt1=0,cnt2=0;
		for (int i=1;i<=n;++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][0]>a[i][1] and a[i][0]>a[i][2]){
				blt[i]=0;++cnt0;
				ans+=a[i][0];
				v[0].push_back(i);
			} else if (a[i][1]>a[i][0] and a[i][1]>a[i][2]){
				blt[i]=1;++cnt1;
				ans+=a[i][1];
			} else{
				blt[i]=2;++cnt2;
				ans+=a[i][2];
			}
		}
		for (int i=1;i<=cnt0-n/2;++i){
			for (int j=1;j<=n;++j)
		}
	}	
	return 0;
}
*/
//Actually Actually Actually Actually Actually Actually Actually Actually
//Actually Actually Actually Actually Actually Actually Actually Actually
//Actually ACTUALLYACTUALLYACTUALLY Im a JVRUO:<
//By Luogu@YzxLeaf's CSP-S2 Alone.At 17p.m.On 2025-11-01.
//All Rights Reserved.
