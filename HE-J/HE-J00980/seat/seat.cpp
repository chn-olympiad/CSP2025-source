#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
bool cmp(int a,int b){return a>b;}
int lie=0,hang=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	int xm=a[1];
	sort(a+1,a+len+1,cmp);
	int sh=0,yu=0;
	for(int i=1;i<=len;i++){
		if(a[i]==xm){
			sh=i/n;
			yu=i%n;
			if(yu==0) lie=sh;
			else lie=sh+1;
			if(lie%2==1){
				if(yu==0) hang=n;
				else hang=yu;
			}
			else{
				if(yu==0) hang=1;
				else hang=n-(yu-1);
			}
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
