#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string aa;
int a[N],l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>aa;
    for(int i=0;i<aa.size();i++){
    	if(aa[i] <= '9' && aa[i]>='0'){
    		a[++l]=aa[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--)  cout<<a[i];
	return 0;
}
