#include<bits/stdc++.h> 
using namespace std;
int a[500005],b[500005];
struct ss{
	int l,r;
}x[500005];
bool cmp(ss x,ss y){
	if(x.r==y.r){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			num+=a[i];
		}
		cout<<num;
		return 0;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				num++;
			}else if(a[i-1]==a[i]){
				a[i-1]=0;
				a[i]=0;
				num++;
			}
		}
		cout<<num;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int z=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				x[z].l=i;
				x[z].r=j;
				z++;
				break;
			}
		}
	}
	sort(x+1,x+z,cmp);
	for(int i=1;i<=n;i++){
		if(x[i].l>x[i-1].r){
			num++;
		}else{
			x[i].r=x[i-1].r;
		}
	}
	cout<<num;
	return 0;
}
