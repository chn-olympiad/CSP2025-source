#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	if(x<y+z&&y<x+z&&z<x+y)
	{
		cout<<1;
	}
	return 0;
}
