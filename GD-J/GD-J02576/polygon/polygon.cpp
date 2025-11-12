#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,a[5001],o,b[5001];
int q;
void gh(int bs,int id,int p,int ma,vector<vector<int> >v) {
	if(id>bs) {
		if(p>ma*2) {
			vector<int>l;
			for(int i=1; i<id; i++) {
				if(b[i]==1) {
					l.push_back(i);
				}
			}
			sort(l.begin(),l.end());

			int g=1;
			for(int i=0; i<q; i++) {
				cout<<i<<' ';
				if(v[i]==l) {
//					for(int i=0; i<l.size(); i++) {
//						cout<<l[i]<<" ";
//					}
//					cout<<"\n";
					g=0;
					break;
				}
			}
			cout<<"\n";
			if(g) {
				v.push_back(l);
				q++;
				o++;
				o%=998;
				o%=244;
				o%=353;
			}

		}
	} else {
		for(int i=1; i<=n; i++) {
			if(!b[i]) {
				p+=a[i];
				ma=max(ma,a[i]);
				b[i]=1;
				gh(bs,id+1,p,ma,v);
				b[i]=0;
			}
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=3; i<=n; i++) {
		vector<vector<int> >v;
		q=0;
		gh(i,0,0,0,v);
	}
	cout<<o;
	return 0;
}

