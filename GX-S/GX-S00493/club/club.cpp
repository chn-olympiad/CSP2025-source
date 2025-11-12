#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct myd{
	int f;
	int s;
	int t;
};
myd a[100005];
int f[100005],s[100005],t[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int m;
	long long my=0;
	for(int i=0;i<n;i++){
		cin>>m;
		my=0;
		int b;
		//int c;
		//int d;
		for(int j=0;j<m;j++){
			cin>>a[j].f>>a[j].s>>a[j].t;
			f[j]=a[j].f;
			s[j]=a[j].s;
			t[j]=a[j].t;
			b=max(f[j],max(s[j],t[j]));
			c=f[j]+s[j]+t[j]-b-min(f[j],min(s[j],t[j]));
			d=min(f[j],min(s[j],t[j]));
			/*if(b-c>c-d){*/
				my+=b;
			/*}
			else if(b-c<c-d){
				my+=d;
			}
			else{
				my+=c;
			}*/
			/*f[j]=b;*/
		}
		/*sort(f,f+m);
		reverse(f,f+m);
		for(int j=0;j<m/2;j++){
			my+=f[j];
		}*/
		cout<<my<<endl;
	}
	return 0;
}
