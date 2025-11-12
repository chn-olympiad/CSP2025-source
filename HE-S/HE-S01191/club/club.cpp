#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int t;
	while(cin>>t) {
		for(int i=1; i<=t; i++) {
			cin>>n;
			for(int j=0; j<3; j++) {
				cin>>a[j];

			}
			if(a[1]==0&&a[2]==0||a[2]==0&&a[3]==0||a[1]==0&&a[3]==0) {
				cout<<"1"<<endl;
				return 0;
			} else if(a[1]==0||a[2]==0||a[3]==0) {
				cout<<"2"<<endl;
				return 0;
			}

		}
	}


	return 0;
}
