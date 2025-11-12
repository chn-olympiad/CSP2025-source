#include<bits/stdc++.h>
using namespace std;
int y[1000005],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int p=a.size();
	for(int i=0;i<p;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			l++;
			y[l]=a[i]-'0';
		}
	}
	sort(y+1,y+1+l);
	for(int i=l;i>=1;i--)
	{
		cout<<y[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

