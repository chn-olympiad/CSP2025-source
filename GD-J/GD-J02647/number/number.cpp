			#include<bits/c++.h>
using namespace std::
string S,a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	for(int i=0;i<S.size();i++)
	{
		if ('0'<=S[i]&&S[i]<='9')
			a[S[i]]+=S[i];
	}
	for(int i=9;i>=0;i--)
		printf("%s",a[i]);
	return 0;
}
