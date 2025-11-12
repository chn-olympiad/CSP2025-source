#include <iostream>;
#include<string>;
using namespace std;
int t[15];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string str;
	cin>>str;
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	int x=a[i];
	sort(t+1;t+1+n*m,cmp);
	for (int i=1;i<=n;i++){
	    if (x==t[i]){
		    int lie =(i-1)/n;
		    int t=i-(lie-1)*n;
		    int hang=(lie&1?m+1-t);

	}
	cout<<lie+1<<x;
	return 0;
}
