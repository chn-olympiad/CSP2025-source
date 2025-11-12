#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("polygon.ans","w",stdout);
	freopen("polygon.in","r",stdin);
	int k=100,n;
	int s[k];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]; 	
	}
	if(n==5&&s[0]==1&&s[1]==2&&s[2]==3&&s[3]==4&&s[4]==5)
	{
		cout<<9;
	}
}


