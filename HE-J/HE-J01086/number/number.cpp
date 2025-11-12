#include<bits/stdc++.h>
using namespace std;
char a[1000050];
int b[1000050];
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	int l=strlen(a),cnt=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]=='0')
		{
			sum++;
		}
		else{
			if(a[i]>'0'&&a[i]<='9')
			{
				b[++cnt]=a[i]-'0';
			}
		}
	}
	sort(b+1,b+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",b[i]);
	}
	if(cnt==0)
	{
		printf("0");
	}
	else
	{
		for(int i=1;i<=sum;i++)
		{
			printf("0");	
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
