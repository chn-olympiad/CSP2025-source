#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,d,l,e,b[20000005];
bool cmp(int s1,int s2){
	return s1>s2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int c,sum=0;
			if(j==i){
				c=a[i];
			}else{
				for(int x=i;x<=j;x++) sum+=a[x];
				c=sum/(j-i);
			}
			if(c==k){
				l+=j-i+1;
				b[d]=j-i+1;
				d++;
				ans++;
			}
		}
	}
	sort(b,b+d,cmp);
	while(l>n){
		l-=b[e];
		ans--;
		e++;
	}
	cout<<ans;
	return 0;
}
