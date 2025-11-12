#include<bits/stdc++.h>
using namespace std;
vector<int>x;
vector<int>y;
vector<bool>b;
vector<int>a;
int sum=0;
int ans=0;
int dp(){
	//不会写（ˉ﹃ˉ） 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
		b.push_back(true);
	}
	for(int i=0;i<n;i++)
	{
		int temp=0;
		for(int j=i;j<n;j++)
		{
			temp=temp^a[j];
			if(temp==k)
			{
//				cout<<i<<","<<j<<" ";
//				x.push_back(i);
//				y.push_back(j);
//				sum++;
				ans++;
			}
		}
	}
//	for(int i=0;i<sum;i++)
//	{
//		cout<<x[i]<<","<<y[i]<<endl;
//	}
	cout<<ans<<endl;
	return 0;
}
//我不会写动规啊啊啊啊啊啊啊啊啊啊(@﹏@)
//算了骗点分得了 
//         ,___          .-;'
//         `"-.`\_...._/`.`
//      ,      \        /
//   .-' ',    / ()   ()\
//  `'._   \  /()    .  (|
//      > .' ;,     -'-  /
//     / <   |;,     __.;
//     '-.'-.|  , \    , \
//        `>.|;, \_)    \_)
//         `-;     ,    /
//            \    /   <
//             '. <`'-,_)
//              '._) 			嘿你别说这搜狗的字符画还挺好看 
