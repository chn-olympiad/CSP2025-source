#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}
int a[100005],b[100005],c[100005],d=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for (int i=1;i<=100001;i++)a[i]=0;
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for (int i=1;i<=n/2;i++){
			d+=a[i];
			d+=b[i];
		}
		cout<<d<<endl;
	}
	
} 
