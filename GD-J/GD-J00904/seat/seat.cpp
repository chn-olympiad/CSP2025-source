#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],g,s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		//cout<<a[i]<<endl;
		if (a[i]==g){
			s=i;
			break;
		}
	}
	int x,y;
	//cout<<s<<endl<<m<<endl;
	if (s%m!=0) x=s/m+1;
	else x=s/m;
	int b=m*(x-1);//前面的人数 
	y=s-b;//正序 
	if (x%2==0) y=m-y+1;
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
