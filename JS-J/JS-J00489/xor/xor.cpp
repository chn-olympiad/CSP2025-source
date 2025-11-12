#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],f[500010],c,v,last;
pair<int,int> p[500010];
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			c=b[j] xor b[i-1];
			if(c == k){
				ans++;
				p[ans].first=i,p[ans].second=j;
			}
		}
		
	for(int i=1;i<=ans;i++){
		if(p[i].first>p[last].second)
			ans++,i=p[i].second,last=p[i].second;
	}
	cout<<v<<"\n";
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

















