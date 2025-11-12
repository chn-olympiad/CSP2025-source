#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e5+10;
std::string str;
int a[N],len,n=0;
signed main(int argc,char *argv[]){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>str;
	len=str.size();
	for(register int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9')
		a[++n]=str[i]-'0';
	}
	sort(a+1,a+n+1);
	for(register int i=n;i>=1;i--){
		std::cout<<a[i];
	}
	return 0;
}
