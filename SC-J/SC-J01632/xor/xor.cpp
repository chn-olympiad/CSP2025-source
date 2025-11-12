#include<bits/stdc++.h>
using namespace std;
//O(n2)
const int N=5e5+10;
int a[N];
int n,k;
struct ans{
	int l,r;
	bool operator <(const ans &b)const{
		if(l==b.l)return r<b.r;
		else return l<b.l;
	}
}ans[N];
int tot=0;
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
/*	for(int i=19;i>=0;i--){
		if(k&(1<<i)){
			for(int j=1;j<=n;j++){
				if(a[j]&(1<<i))
			}
		}
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long tmp=a[i];
			for(int m=i+1;m<=j;m++){
				tmp^=a[m];
			}
			if(tmp==k){
				ans[++tot].l=i,ans[tot].r=j;
			}
		}
	}
	if(!tot){
		cout<<0;
		exit(0);
	}
	sort(ans+1,ans+1+tot);
	//for(int i=1;i<=tot;i++)cout<<ans[i].l<<" "<<ans[i].r<<endl;
	int mr=1e9+10,ans2=0;
	for(int m=1;m<=tot;m++){
		if(ans[m].r<mr)mr=ans[m].r;
		if(ans[m].l>=mr){
			ans2++;
			mr=ans[m].l;
		}
	}
	cout<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//4 2
//2 3 0 1 