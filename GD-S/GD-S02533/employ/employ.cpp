#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n=0,m=0,sum=1,ans=0,i=0,j=0,k=0;
int win=0, defeat=0;
string s="";
int a[114514]={};
int C[666][666]={};
bool tea=1;
vector<int>v;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (i=1;i<=n;i++){
		cin >> a[i];
		
	}
	if (s.find("0")!=-1)tea=0; 
	if (tea){
		//特殊性质a
		//ans = An,m， An,m =Cn,m *m! 
		C[0][0]=1;
		C[0][1]=1;C[1][1]=1;
		C[2][0]=1;C[2][1]=2;C[2][2]=1;
		for (i=3;i<=n;i++)
			{
			C[i][0]=1;
			for (j=1;j<=i;j++)
				C[i][j]=C[i-1][j]+C[i-1][j-1], C[i][j] %= mod;
			}
		/*for (i=1; i<=n; i++)
		{
			for (j=1;j<=i;j++)
				cout << C[i][j]<<" ";
			cout<<endl;
		}*/
		sum = C[n][m];
	//	cout << sum;
		for (i=1; i<=m; i++)
			{
			sum *= i;
			sum %= mod;
			}
		cout << sum;
	}
	else
	{
		//暴力代码 
		for (i=1; i<=n; i++) v.push_back(i);
		int fac=1;
		for (i=1;i <=n; i++) fac*=i;
		for (i=1;i<=fac;i++)
		{
			//直接模拟当前的
			win=0,defeat=0;
			for (j=1;j<=n;j++)
			{
				if (a[v[j-1]] <=defeat)defeat++;
				else {
					if (s[j-1] == '0')defeat++;
					else if (a[v[j-1]] > defeat)win++;
				}
			 } 
			 if (win >=m) ans++;
			next_permutation(v.begin(),v.end());
		}
		cout << ans;
		
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
