#include<bits/stdc++.h>
using namespace std;
struct stu{long long l,r;};
long long n,k,a[500005],b[500005],mi,ans;
vector<stu> ve;
bool cmp(stu l,stu r){
	if(l.r!=r.r) return l.r<r.r;
	return l.l<r.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				stu t;
				t.l=i,t.r=j;
				ve.push_back(t);
				break;
			}
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	mi=0;
	for(int i=0;i<ve.size();i++){
		if(ve[i].l>mi) mi=ve[i].r,ans++;
//		cout<<ve[i].l<<" "<<ve[i].r<<"\n";
	}
	cout<<ans;
	return 0;
}
