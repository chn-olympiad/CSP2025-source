#include<bits/stdc++.h>
using namespace std;
namespace code{
#define F(i,x,y) for(int i=x,__=y;i<=__;i++)
#define R(i,x,y) for(int i=y,__=x;i>=__;i--)
#define debug(x) cerr<<#x<<"="<<x<<endl
	using ll=long long;
	using uint=unsigned int;
	using ull=unsigned long long;
	const int N=100005;
	vector<int>a1,a2,a3;
	int a[4][N];
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin.tie(0)->sync_with_stdio(0);
		int T;
		cin>>T;
		while(T--){
			a1.clear();a2.clear();a3.clear();
			int n;
			cin>>n;
			int s=0;
			F(i,1,n){
				cin>>a[1][i]>>a[2][i]>>a[3][i];
				if(a[1][i]>a[2][i]){
					if(a[1][i]>a[3][i]){
						s+=a[1][i];
						a1.push_back(i);
					}
					else {
						s+=a[3][i];
						a3.push_back(i);
					}
				}
				else {
					if(a[2][i]>a[3][i]){
						s+=a[2][i];
						a2.push_back(i);
					}
					else {
						s+=a[3][i];
						a3.push_back(i);
					}
				}
			}
			if(a1.size()>n/2){
				for(int& j:a1){
					j=max(a[2][j],a[3][j])-a[1][j];
				}
				sort(a1.begin(),a1.end(),[](int x,int y)->bool{return x>y;});
				F(i,0,a1.size()-n/2-1){
					s+=a1[i];
				}
			}
			else if(a2.size()>n/2){
				for(int& j:a2){
					j=max(a[1][j],a[3][j])-a[2][j];

				}
				sort(a2.begin(),a2.end(),[](int x,int y)->bool{return x>y;});
				F(i,0,a2.size()-n/2-1){
					s+=a2[i];
				}
			}
			else if(a3.size()>n/2){
				for(int& j:a3){
					j=max(a[1][j],a[2][j])-a[3][j];
				}
				sort(a3.begin(),a3.end(),[](int x,int y)->bool{return x>y;});
				F(i,0,a3.size()-n/2-1){
					s+=a3[i];
				}
			}
			cout<<s<<'\n';
		}
		return 0;
	}
}
int main(){
	code::main();
	return 0;
}