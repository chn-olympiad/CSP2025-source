#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int n,q;
string s1[200005],s2[200005];
map <int,int> sum;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
		sum[(int)(s1[i].find('b')-s2[i].find('b'))]++;
	}
	string t1,t2;
	while (q--){
		cin>>t1>>t2;
		if (t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=t1.find('b')-t2.find('b');
		cout<<sum[cnt]<<endl;
	}
	return 0;
}
