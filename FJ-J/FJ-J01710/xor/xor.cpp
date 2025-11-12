#include<bits/stdc++.h>
using namespace std;
struct lr{
	int l,r;
};
vector<lr> llrr;
vector<int> a,s;
int n,k,x;int ans;
bool cmp(lr x,lr y){
	if(x.r==y.r) return x.l>y.l;
	return x.r<y.r;
}
bool pd(int l1,int r1,int l2,int r2){
	if(l2<=l1&&r2>=l1){
		return 0;
	}
	if(r1>=l2&&r1<=r2){
		return 0;
	}
	if(l2<=l1&&r2>=r1){
		return 0;
	}
	if(l1<=l2&&r2<=r1){
		return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>x;
	a.push_back(x);
	s.push_back(x);
	for(int i=1;i<n;i++){
		cin>>x;
		a.push_back(x);
		s.push_back(s[i-1]^x);
	}
	if(a[0]==k){
		ans++;
		lr tr;
		tr.l=0,tr.r=0;
		llrr.push_back(tr);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((s[j]^s[i-1])==k){
				ans++;
				lr tr;
				tr.l=i,tr.r=j;
				llrr.push_back(tr);
			}
		}
	}
	sort(llrr.begin(),llrr.end(),cmp);
	for(int i=0;i<llrr.size()-1;i++){
		for(int j=i+1;j<llrr.size()-1;j++){
			if(pd(llrr[i].l,llrr[i].r,llrr[j].l,llrr[j].r)){
				break;
			}
			else{
				llrr.erase(llrr.begin()+j);
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}
