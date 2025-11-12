#include<bits/stdc++.h>
using namespace std;
int a[1005];
struct fl{
	int s;
	int e;
};
int cnt=1;
fl b[100005];
int n,k;
bool cmp(fl a,fl b){
	if(a.e==b.e)return a.s<b.s;
	return a.e<b.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(b,114514,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now;
	for(int i=1;i<=n;i++){now=a[i];
		for(int j=i;j<=n;j++){
			for(int z=i+1;z<=j;z++)now^=a[z];
			if(now==k)b[cnt].s=i,b[cnt].e=j,cnt++;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	sort(b+1,b+cnt,cmp);
	int ans=0;
	int con=1;
	int last=0;
	while(con<cnt){
		if(last>=b[con].s){
			con++;
			continue;
		}
		ans++;
		last=b[con].e;
	}
	cout<<ans<<endl;
    return 0;	
}
