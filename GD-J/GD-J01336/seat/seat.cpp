#include<bits/stdc++.h>
using namespace std;
int n,m,pos,a[102];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=0;i<sum;++i) cin>>a[i];
	int x=a[0];
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;++i)
		if(a[i]==x){
			pos=i;
			break;
		}
	int line=pos/n+1,row=(line%2?pos%m+1:m-(pos%m));
	cout<<line<<' '<<row;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
