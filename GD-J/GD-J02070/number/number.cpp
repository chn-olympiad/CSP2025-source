#include <iostream>
#include <fstream>
using namespace std;
int a[10],i,j,k;
string b;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(i=0; i<b.size(); i++)
		if(b[i]-'0'>=0&&b[i]-'0'<=9)
			a[b[i]-'0']++;
	for(i=9; i>=0; i--){
		if(i==0&&k==0)cout<<0;
		else if(a[i]){
			if(i!=0)k=1;
			for(j=0; j<a[i]; j++)
				cout<<i;
		}
	}
	return 0;
}
