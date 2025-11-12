#include<bits/stdc++.h>
using namespace std;
struct st{
int beg;
int end;
};
st b[100000];
bool cmp(st a,st b){
if(a.beg=b.beg) return a.end<b.end;
else return a.beg<b.beg;
}
void ho(int o,int l){
for(int i=o+1;i<=l;i++){
b[i-1].beg=b[i].beg;
b[i-1].end=b[i].end;
}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[1005],l=0;
	bool l1=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) l1=0;
	}
	if(k==0&&l1) cout<<0;
	else {
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				int l=a[i];
				for(int z=i; z<=j; z++) l=l|a[z];
				if(l==k) {
					b[l+1].beg=i;
					b[l+1].end=j;
					l++;
				}
			}
		}
		cout<<l<<endl;
		sort(b+1,b+l+1,cmp);
		for(int i=1;i<=l;i++){
		if(b[i].beg=b[i+1].beg){
		while(b[i].beg==b[i+1].beg){
		ho(i+1,l);
		l--;
	}
		}
		if(b[i].end<b[i+1].end) ans++;
		}
		cout<<ans;
	}
	return 0;
}