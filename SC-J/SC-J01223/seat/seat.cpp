#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,f,g,h;
struct T{
	int s;
	int id;
}t[N];
bool cmp(T x,T y)
{
	return x.s>y.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>t[i].s;
		t[i].id=i;
	}
	sort(t+1,t+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t[i].id==1)
		{
			f=i;
			break;
		}
	}
	g=f/n;
	h=f%n;
	if(h==0){
		if(g%2==0) cout<<g<<" "<<1;
		else cout<<g<<" "<<n;
	}else{
		if(g%2==0) cout<<g+1<<" "<<h;
		else cout<<g+1<<" "<<n-h+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}