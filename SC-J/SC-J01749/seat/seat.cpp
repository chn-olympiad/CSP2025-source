#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
const int maxn=110;
int n,m,cnt=1;
int a[maxn],s[20][20],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);//b[1]表示小R的成绩
	for(int j=1;j<=n;j++)//行 
	{
		if(j%2==1)//行  蛇形排列 
		{
			for(int i=1;i<=m;i++){
				s[i][j]=a[cnt];
//				cout<<a[cnt]<<"\n";
				if(a[cnt]==r) cout<<j<<" "<<i; 
				cnt++;
			} 
		}
		else
		{
			for(int i=m;i>=1;i--)
			{
				s[i][j]=a[cnt];
//				cout<<a[cnt]<<"\n";
				if(a[cnt]==r) cout<<j<<" "<<i;
				cnt++;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<endl;
//	}	
	return 0;
} 