//GZ-S00028 遵义市第十二中学 何菁菁
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

int t,n,a1,a2,a3,n1=0,n2=0,n3=0,sum=0,s,r=0;
long long w[10];

cin>>t;
for (int j=1;j<=t;j++){


	cin>>n;
	s=n/2;
for (int i=1;i<=n;i++)
{
	cin>>a1>>a2>>a3;
	if (a1>=a2&&a1>=a3)
	{

		if (n1>s){

			sum+=max(a2,a3);
			if (a2>=a3&&n2<=s-1)
			{
				n2++;
			}
			else n3++;
	}
		else{
			n1++;
			sum+=a1;
			}

	}
	else if(a2>=a1&&a2>=a3)
	{

		if (n2>s){

			sum+=max(a1,a3);
			if (a1>=a3&&n1<=s-1)
			{
				n1++;
			}
			else n3++;
	}
		else{
			n2++;
			sum+=a2;
			}

	}
	else
	{
			if (n3>s){

			sum+=max(a2,a1);
			if (a2>=a1&&n2<=s-1)
			{
				n2++;
			}
			else n1++;
	}
		else{
			n3++;
			sum+=a3;
			}

	}

}w[r]=sum;
r++;sum=0;n1=0;n2=0;n3=0;


}for (int i=0;i<r;i++)
{
	cout<<w[i]<<endl;
}


return 0;
}

