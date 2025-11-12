#include<bits/stdc++.h>
using namespace std;
int a[1000100];
char s;
int cmp(int x,int y){
	return x>y;
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int i=0;
	while (cin>>s && s!=EOF)
	{
		if (s>='0' && s<='9')
		{
			a[i]=s-'0';
			++i;
		}
	}
	sort(a,a+i,cmp);
	for (int j=0;j<i;j++){
		printf("%d",a[j]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
