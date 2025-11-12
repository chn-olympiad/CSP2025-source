#include<bits/stdc++.h>
using namespace std;
int A[105],B[12][12];
signed main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>A[i];
	}
	int a=A[1],b;
	sort(A+1,A+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		if(A[i]==a)
		{
			b=t;
			break;
		}
		t++;
	}
	t=n*m;
	
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
//			cout<<101<<endl;
			for(int j=1;j<=n;j++){
//				cout<<i<<' '<<j<<endl;
				B[j][i]=A[t];
				t--;
			}
		}
		
		if(i%2==0)
		{
//			cout<<102<<endl;
			for(int j=n;j>=1;j--){
//				cout<<i<<' '<<j<<endl;
				B[j][i]=A[t];
				t--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			cout<<B[i][j]<<" ";
			if(B[i][j]==a)
			{
				cout<<j<<" "<<i;
			}
		}
//		cout<<endl;
	}
	return 0;
}

//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);


/*
8:46
bushi
what this???
T1 is harder than T2 and T3 for me...

9:02
thanks for baoli
I AC(yes?) T1 for 30 min...
orz

9:05
xiao L guo bu liao di yi lun !!!
n*m<=100?
xiao L bu neng wei fu fen...

9:26
It use 1.145 s.
I'm very tried.
I sleep at today 0:43...

9:30
T2 is very easy for me.
I want sleep!!!

9:49
em... 
ti kan cuo le
qwq

10:16
bushi
for(int i=1;i<=2;i++) wei sha zhi xun huan yi ci a?????

10:25
2%2!=0!!!

10:28
T2 AC
*/