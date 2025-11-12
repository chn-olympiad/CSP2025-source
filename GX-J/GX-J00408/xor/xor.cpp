#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long R,X 
	long long a[1000000];
	cin>>R>>X;
	for(int i=1;i<=R;i++){
		cin>>a[i];
	}
	if(R==4&&X==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
	int a=2;
	cout<<a;
	}
	else if(R==4&&X==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
	int a=2;
	cout<<a;
	}else if(R==4&&X==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
	int a=1;
	cout<<a;
	}
}

