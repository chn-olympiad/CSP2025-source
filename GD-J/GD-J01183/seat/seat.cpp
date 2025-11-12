#include<bits/stdc++.h>
using namespace std;
int n,m,s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int p=s[1];
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(s[i]==p){
			p=i;
			break;
		}
	p=n*m-p+1;
	int h=p/n;
	int l=p%n;
	if(h%2==1&&l==0)l=n;
	if(h%2==0&&l==0)l=1;
	for(int i=1;i<n;i++){
		if(h%2==1&&l==i)h+=1,l=n-i+1;
		if(h%2==0&&l==i)h++;
	}
	cout<<h<<' '<<l;
	return 0;
}
