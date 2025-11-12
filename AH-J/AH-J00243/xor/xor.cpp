#include<bits/stdc++.h> 
using namespace std;
long long n,a[500005],ans,d[500005],len,k,flag[500005],iss,shaobing,sum;
long long other[500005];
struct node{
	long long b,e;
}ca[500005];
bool cmp(node x,node y){
	if (x.e!=y.e)
		return x.e<y.e;
	return x.b<y.b;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	d[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i==1)
			d[i]=a[i];
		else
			d[i]=(d[i-1]^a[i]);
	}
	if (n<=1005){
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if ((d[j]^d[i-1])==k){
				len++;
				ca[len].b=i;
				ca[len].e=j;
	}
	sort(ca+1,ca+len+1,cmp);
	if (len==0){
		cout<<0;
		return 0;
		}
	for (int i=1;i<=len;i++){
		sum=1;
		shaobing=ca[i].e;
		for (int j=i+1;j<=len;j++){
			if (ca[j].b>shaobing){
				sum++;
				shaobing=ca[j].e;
				}
			}
		ans=max(ans,sum);
		}
	cout<<ans;
	}
	else{
		if (k==1){
			for (int i=1;i<=n;i++)
				if (a[i]==1)
					ans++;
			cout<<ans;
			return 0;
			}
		if (k==0){
			for (int i=1;i<=n;i++){
				if (a[i]==0)
					ans++;
				else if (a[i]==1&&a[i+1]==1&&!other[i]){
					ans++;
					other[i]=1;
					other[i+1]=1;
				}
			}
			cout<<ans;
			return 0;
			}
		}
	return 0;
}
