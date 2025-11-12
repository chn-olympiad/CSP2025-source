#include<bits/stdc++.h>
using namespace std;
int num[1000005];
string str;
int ind;
void qsort(int* l,int* r)
{
	int cnt[10];
	memset(cnt,0,sizeof cnt);
	int* tmp = l;
	while(r-tmp > 0) ++cnt[*(tmp++)];
	for(int i=0;i<=9;++i) for(int j=0;j<cnt[i];++j) *(l++) = i;
	delete[] tmp;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();++i)
		if(str[i] >= '0' && str[i] <= '9') num[ind++] = str[i]-'0';
	qsort(num,num+ind);
	for(int i=ind-1;i>=0;--i) cout<<num[i];
	return 0;
}
