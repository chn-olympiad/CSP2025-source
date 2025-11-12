#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],now,cnt,x[N],num,last;
struct xxoorr{
	int l,r;
}re[N];
bool cmp(xxoorr a,xxoorr b){
	if(a.l!=b.l){
		return a.l<b.l;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//CCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCF 
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		if(a[i]==k){
			num++;
			re[num].l=i;
			re[num].r=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=1){
				now=x[j]^x[i-1];
			    if(now==k){
			    	num++;
			    	re[num].l=i;
			    	re[num].r=j;
			    }
			}
		}
	}
	sort(re+1,re+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(re[i].l>last){
			cnt++;
			last=re[i].r;
		}
	}
	cout<<cnt;
	return 0;
} 
