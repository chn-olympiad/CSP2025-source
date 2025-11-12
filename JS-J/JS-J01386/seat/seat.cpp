#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[1000000];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>m>>n;
for(int i=0;i<m*n;i++){
	cin>>a[i];
	}
	int x=a[0];
	int s;
	sort(a,a+m*n);
	for(int i=0;i<m*n;i++){
            if(a[i]==x){
              s=m*n-i;
              break;
            }
		}int y=0;
	if(s%m==0){cout<<s/m<<" ";y=s/m;}
	else {cout<<s/m+1<<" ";y=s/m+1;}
	int w=1;
	int f=1;
    w=s-(y-1)*m;
    if(y%2==0)cout<<m-w+1;
    else cout<<w;
return 0;
}
