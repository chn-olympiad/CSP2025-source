#include <iostream>
#include <iomanip> 
using namespace std;
int a[5009];
int n;
int max;
int l,r;
int subtot=0;
int submax=0;
int totnum=0;

int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=3;i<=n;i++){
		for (int l=1;l<=n;l++){
			r=l+i;
			for (int k=l;k<=r;k++){
				subtot+=a[k];
				if (a[k]>submax){
					submax=a[k];
				}
			}
			if (subtot>2*submax){
				totnum++;
			}
			subtot=0;
		}
	}
	cout<<((totnum%998)%244)%353;
	return 0;
}
