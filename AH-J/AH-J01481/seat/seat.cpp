#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[110],s[110][110],R,i=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+(n*m),cmp);
    for(int c=1;c<=m;c++){
        if(c%2==1){
           for(int r=1;r<=n;r++){
               s[r][c]=a[i];
               i++;
               if(s[r][c]==R){
			      cout<<c<<' '<<r;
			      return 0;
			   }
           }
       }
       else{
           for(int r=n;r>=1;r--){
               s[r][c]=a[i];
               i++;
               if(s[r][c]==R){
			      cout<<c<<' '<<r;
			      return 0;
			   }
           }
       }
    }
	return 0;
}
