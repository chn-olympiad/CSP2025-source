#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int person=n*m;
	int grade[person+10];
	int r,rr,rrr,rrrr,rrrrr;
	for(int i=1;i<=person;i++)
	{
		cin>>grade[i];
	}
	r=grade[1];
	sort(grade,grade+person);
	for(int i=1;i<=person;i++)
	{
		if(grade[i]==r);
		rr=i;
	}
			rrr=rr/(2*n);
			rrrr=(rrr+1)*2;
			if(rr%(n*2)>n) m=rrrr;
			else m=rrrr-1;
			rrrrr=m*n;
			n=rrrrr-rr;
			cout<<n<<' '<<m<<endl;
    return 0;
}
