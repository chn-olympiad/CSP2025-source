#include<bits/stdc++.h>
#define int long long
#define N 1001
using namespace std;

#define gc getchar()
void read(int &n){int l=1,num=0;char ch;
while(ch=gc,ch<'0'||ch>'9')if(ch=='-')
l=-1;num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=l*num;return;}
int n,m,ansx,ansy,num,a[N];
bool cmp(int x,int y){return x>y;}

signed main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n*m;i++)cin>>a[i];
	num=a[1];sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==num){
		ansx=i%n==0?i/n:i/n+1;ansy=i%n==0?n:i%n;
		if(ansx%2==0)ansy=n-ansy+1;
		cout<<ansx<<" "<<ansy;return 0;
	}
	return 0;
}


