#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,k=0;
	scanf("%d",&x);
	for(int i=2;i<=n*m;i++)
	{
		int y;
		scanf("%d",&y);
		if(y>x)k++;
	}
	k++;
	//
	int ansn,m1,ansm;
	//Çóansn 
	ansn=(k%n)? k/n+1:k/n;
	//Çóm1
	m1=(ansn-1)*n;
	//Çóansm!
	int w=k-m1;
	ansm=ansn%2? w:m-w+1;
	//goodbye 
	printf("%d %d",ansn,ansm);
	return 0;
}
