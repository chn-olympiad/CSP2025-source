#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("road.in","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;cin>>n;
	srand(time(NULL));srand(rand()%(n^time(NULL)));
	for(int i=1;i<=rand()%1000;i++) srand(rand()*rand()%rand()*rand()%rand());
	cout<<rand()%99999999<<'\n';
	
	return 0;
}
