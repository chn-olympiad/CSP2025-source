#include <bits/stdc++.h>
using namespace std;
int n,q,l,r;
string T1,T2,t1,t2;
struct node{
	string S1,S2,s1,s2,L,R;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i].S1>>a[i].S2;
		l=0,r=a[i].S1.size()-1;
		while (l<=r){
			if (a[i].S1[l]!=a[i].S2[l]) break;
			l++;
		}
		while (r>=l){
			if (a[i].S1[r]!=a[i].S2[r]) break;
			r--;
		}
		a[i].L=l,a[i].R=r;
		for (int i=l;i<=r;i++){
			a[i].s1[i-l]=a[i].S1[i];
			a[i].s2[i-l]=a[i].S2[i];
		}
	}
	while (q--){
		cin>>T1>>T2;
		if (T1.size()!=T2.size()){
			cout<<0<<endl;
			continue;
		}
		l=0,r=T1.size()-1;
		while (l<=r){
			if (t1[l]!=t2[l]) break;
			l++;
		}
		while (r>=l){
			if (t1[r]!=t2[r]) break;
			r--;
		}
		for (int i=l;i<=r;i++){
			t1[i-l]=t1[i];
			t2[i-l]=t2[i];
		}
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (a[i].s1==t1 && a[i].s2==t2){
				int flag=1;
				for (int j=l-a[i].L;j<=r+a[i].R;j++){
					if (t1[j]!=a[i].s1[j]){
						flag=0;
						break;
					}
				}
				for (int j=l-a[i].L;j<=r+a[i].R;j++){
					if (t2[j]!=a[i].s2[j]){
						flag=0;
						break;
					}
				}
				if (flag) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
