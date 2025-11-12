#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a1,a2,a3,m,wz,qh,adx,bdx,cdx;
	cin>>n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	for (int k=0;k<n;k++){
		cin>>m;
		wz=m/2;
		qh=0;
		while (m--){
			cin>>a1>>a2>>a3;
			a.push_back(a1);
			b.push_back(a2);
			c.push_back(a3);
		}
		for (int i=adx;i>0;i--){
			for (int j=1;j<adx;j++){
				if (a[i]>=a[j]){
					a.insert(a.begin()+j,a[i]);
					b.insert(b.begin()+j,b[i]);
					c.insert(c.begin()+j,c[i]);
					break;
				}
			}
		}
		for (int i=0;i<wz;i++){
				qh+=a[i];
			}
			cout<<qh<<endl;
	}
}
