#include <bits/stdc++.h>
using namespace std;
struct p{
	int l;
	int r;
}b[100005];
bool cmp(p x,p y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,p=0,pf=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		p=a[i];
		if(p==k){
			sum++;
			b[sum-1].l=i;
			b[sum-1].r=i;
			//cout<<i<<" "<<i<<endl;
			continue;
		}
		for(int j=i+1;j<n;j++){
			p=p^a[j];
			if(p==k){
				sum++;
				b[sum-1].l=i;
				b[sum-1].r=j;
				//cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	//cout<<sum<<endl;
	sort(b,b+sum,cmp);
	int ri=-1,t=sum;
	for(int i=0;i<sum;i++){
		//cout<<b[i].l<<" "<<b[i].r<<endl;
		if(b[i].l<=ri){
			t--;
			continue;
		}
		ri=b[i].r;
	}
	cout<<t<<endl;
	return 0;
}
