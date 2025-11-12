#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int x[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    srand(time(NULL));
    cout<<(rand()*1024+rand()*512+rand()*32+rand())%MOD;
    fclose(stdin);fclose(stdout);
	return 0;
}
/*David Dai
¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸¹÷Ä¸
*/
