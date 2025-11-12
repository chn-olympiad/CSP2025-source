#include<bits/stdc++.h>
using namespace std;
struct feel{
	int x,y,z;
	char b;
}a[10086];
char maxs(int a,int b,int c){
	if(a>=b&&a>=c)
	   return 'a';
	if(b>a&&b>c)
	   return 'b';
	if(c>a&&c>b)
	   return 'c'; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T!=0){
		T--;
		int n,maxn=0,sum=0;
	    cin>>n;
	    for(int i=1;i<=n;i++){
		    cin>>a[i].x>>a[i].y>>a[i].z;
		    a[i].b=maxs(a[i].x,a[i].y,a[i].z);
		    if(a[i].b=='a')
		    sum=a[i].x;
		    if(a[i].b=='b')
		    sum+=a[i].y;
		    if(a[i].b=='c')
		    sum+=a[i].z;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
