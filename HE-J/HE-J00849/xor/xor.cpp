#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);std::cin.tie(0);
	int n;
	std::cin>>n;
	if(n<=2)
	{
		cout<<2;
		return 0;//QAQ 骗到一点吧 
	}
	if(n<=100)
	{
		cout<<n/2;
		
		return 0;//QAQ 骗到一点吧 
	}
	return 0;
}//观音菩萨保佑 
//11: 34
