#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c;
int cmp(int x,int y)
{
	if(x>y) return 1;
	else return 0;
}

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
b=a[1];
sort(a+1,a+(n*m)+1,cmp);
for(int i=1;i<=n*m;i++){
	if(b==a[i]){
		b=i;
		break;
	}
}
c=(b/m);
if(b-(c*m)==0&&c%2==1){
	cout<<c<<" "<<n<<endl;
}else if(b-(c*m)==0&&c%2==0){
	cout<<c<<" "<<1<<endl;
}else if(c%2==0) cout<<c+1<<" "<<b-(c*m)<<endl;
else cout<<c+1<<" "<<m-(b-(c*m))+1<<endl;
return 0;
}
