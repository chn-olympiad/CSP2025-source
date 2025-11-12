#include<bits/stdc++.h>
using namespace std;
long long j,b[1000001],c;
string a;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	c=a.size();
	for(long long i=0;i<c;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[++j]=a[i]-'0';
		}
	}
	sort(b+1,b+j+1,cmp);
	for(long long i=1;i<=j;i++)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4（蜜马）
*/
