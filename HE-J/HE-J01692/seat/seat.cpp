#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e5+10;
int n,m,a[maxn],w,iq;
bool cmp(int a,int b) 
{
	return a>=b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	w=n*m;
	for (int i=1; i<=w; i++)
		cin>>a[i];
	int y=a[1];
	sort(a+1,a+w+1,cmp);
	for (int i=1; i<=w; i++) {
		if (a[i]==y)
			iq=i;
	}
	if (iq<=n)
		cout<<1<<" "<<iq;
	else
	{
		if (iq%2==0)
			cout<<iq/n+1<<" "<<m-iq%n+1;
		else
			cout<<iq/n+1<<" "<<iq%n;
	}		
	return 0;
}

//3 3
//94 95 96 97 98 99 100 93 92
//#Shang4Shan3Ruo6Shui4
