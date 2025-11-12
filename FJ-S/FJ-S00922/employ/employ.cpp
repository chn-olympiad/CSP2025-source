#include<bits/stdc++.h>
#define modn 998244353
using namespace std;
unsigned long long T(int x){
	unsigned long long r=1;
	for (int i=2;i<=x;i++){
		r*=i;
		r%=modn;
	}
	return r;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char havez=0;
	char havepz=0;
	char s[1000]={0};
	int p[1000];
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
	do{
		cin >> s[i];
	}while (s[i]<'0' || s[i]>'1');
	if (s[i]=='0') havez=1;
	}
	for (int i=0;i<n;i++)
	{
		cin >> p[i];
		if (p[i]==0)
		havepz=1;
	}
	if (n==m && (havez||havepz))
	{
	printf("0\n");return 0;
	}
	else if(havez==0){
		cout << T(n) << endl;
		return 0;
	}
	
}
