#include <iostream>
using namespace std;
int n,ac,bc,cc,t;
int a[10010],b[10010],c[10010];
int main(){
	freopen("clab.in","r",stdin);
	freopen("clab.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}int max=0;
		for(int i=n;i>0;i--){
			for(int j=0;j<i;j++){
				max+=a[i]>b[i]&&a[i]>c[i]?
					a[i]:
					(b[i]>a[i]&&b[i]>c[i]?
					b[i]:c[i]);
			}
		}
		cout <<max;
	}
}
