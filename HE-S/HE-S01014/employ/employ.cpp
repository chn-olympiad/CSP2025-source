#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[505]={ };
int a[505]={ };
int t[505]={ };
char s[105]={ };
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){t[i]++;}
		t[i]+=t[i-1]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
