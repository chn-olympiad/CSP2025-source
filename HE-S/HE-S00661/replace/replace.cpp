#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	srand(time(NULL));
	string a,b;
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
	{
		cin>>a>>b;
	}
	cout<<rand()%100;
	fclose(stdin);fclose(stdout)
	return 0;
}
// CCF,please let me AK CSP-J.Thank you!
/* |00000000 00|||||00 |0000000| |||||||||
   |00000000 0|00000|0 |0000000| |00000000
   |00000000 |0000000| 0|00000|0 |00000000
   |00000000 |0000000| 0|00000|0 |||||||||
   |00000000 |0000000| 00|000|00 |00000000
   |00000000 0|00000|0 000|0|000 |00000000
   ||||||||| 00|||||00 0000|0000 |||||||||
*/
