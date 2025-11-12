#include<bits/stdc++.h>
using namespace std;
const int N=12;
struct per{
	int pos,x;
}a[N*N+5];
int n,m,s=0;
bool cmp(per a,per b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[++s].x;
		a[s].pos=s;
	}
	sort(a+1,a+s+1,cmp);
	int pos;
	for(int i=1;i<=s;i++){
		if(a[i].pos==1){
			pos=i;break;
		}
	}
	//cout<<pos<<endl;
	int x=(pos+n-1)/n;
	int f=x%2,y;
	if(f==1) y=pos-n*(x-1);
	else y=n-(pos-n*(x-1))+1;
	cout<<x<<" "<<y;
	fclose(stdin);fclose(stdout);
}
/*3 3
94 95 96 97 98 99 100 93 92
*/
