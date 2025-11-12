#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int N=1e6+10;
string a;
int n,f[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++) if(a[i]>='0'&&a[i]<='9') f[int(a[i]-'0')]++;
	for(int i=9;i>=0;i--) if(f[i]) for(int j=1;j<=f[i];j++) cout<<i;
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/
