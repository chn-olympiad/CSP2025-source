#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,x,a,h=0;
	vector<long long>s;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a;
		s.push_back(a);
		if(i==1){
			x=a;
		}
	}
	sort(s.begin(),s.end(),greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++)
			{
				h++;
				if(s[h-1]==x){
					cout<<i<<' '<<j;
				}
			}
		}
		else{
			for(int j=n;j>0;j--)
			{
				h++;
				if(s[h-1]==x){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	return 0;
}
