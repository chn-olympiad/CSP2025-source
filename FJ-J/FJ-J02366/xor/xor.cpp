#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n,k,tot,last;
bool l=0;
map<int,int>m;//存储异或值 
array<int,500001>a,x;//原数组 异或数组

int main(int argc,char**argv) {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1; i<=n; ++i) cin>>a[i];

	x[1]=a[1];
	for(int i=2; i<=n; ++i) x[i]=x[i-1]^a[i];

	for(int i=1; i<=n; ++i) {
		if(a[i]==k) { //1(如果可以直接相等)
			//cout<<"1\n";
			tot++;
			last=x[i];
			l=1;
			m.clear();
		} else {
			if(!l&&(x[i]==k||m[x[i]^k])) {//2([第一个区间]可以以获得到k)
				//cout<<"2\n";
				tot++;
				last=x[i];
				l=1;
				m.clear();
			} else if(l&&((x[i]^last)==k||m[x[i]^last^k]==1)) { //3([其他区间]可以以获得到k)
				//cout<<"3 "<<'\n';
				tot++;
				last=x[i];
				l=1;
				m.clear();
			} else {//存入 
				if(l)
					m[x[i]^last]=1;
				else
					m[x[i]]=1;
			}
		}
	}

	cout<<tot;

	return 0;
}
