#include<bits/stdc++.h>
using namespace std;
int a[100010],n,m,x,len;
int cmp(int xx,int yy){return xx>yy;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){cin>>a[++len];}
	x=a[1];
	int pos;
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)if(x==a[i]){pos=i;break;}
	int h,l;
	l=ceil(pos*1.0/n);
	if(l%2==1){h=pos%n;if(h==0)h=n;}
	else{h=n-pos%n+1;if(h==n+1)h=1;}
	cout<<l<<" "<<h;
	return 0;
}
//feropen("seat.in","r",stdin);
//freopne("seat.out","w",stdout);
//frepoen("seat.in","r",stdin);
//freoepn("seat.out","w",stdout);
