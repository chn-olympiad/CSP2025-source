#include <bits/stdc++.h>
using namespace std;
string s;
const int N=1e6;
char w[N];
long long len,j=0,n[N],num=0;
bool flag[N]={0};
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			flag[i]=1;
			num++;
		}
		else
		{
			flag[i]=0;
		}
	}
	for(long long i=0;i<len;i++){
		if(flag[i]==1){
			w[i]=s[i];
			n[i]=(int)w[i]-48;
		}
	}
	for(long long i=0;i<len;i++){
		for(long long j=0;j<len;j++)
			if(n[j]<n[j+1])	swap(n[j],n[j+1]);
	}
	for(long long i=0;i<num;i++)	cout << n[i];
	return 0;
}
