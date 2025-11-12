#include <bits/stdc++.h>
using namespace std;
struct T{
	int q,p;
}t[500005];
bool cmp(T x,T y){
	return x.p<y.p;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int a[n+5],rec=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for (int i=1;i<=n;i++){
		int h=0;
		for (int j=i;j<=n;j++){
			h=(h^a[j]);
			if (h==k){
				rec++;
				t[rec].q=i,t[rec].p=j;
				break;
			}
		}
	}
	sort(t+1,t+rec+1,cmp);
	long long cnt=0,r=0;
	for (int i=1;i<=n;i++){
		if (t[i].q>r){
			cnt++;
			r=t[i].p;
		}
	}
	cout<<cnt;
	return 0;
}
