#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=5e5+10;
int a[N],s[N],ma=0,mi=INT_MAX;
int l,r,mid;
 unordered_map <int,int> mp[N];
signed main(){
	
//	
//	freopen("xor6.in","r",stdin);
//	freopen("xor6.out","w",stdout);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
	ma=max(ma,a[i]);
	mi=min(mi,a[i]);
//	mp[i]=mp[i-1];
//	mp[i][s[i]]++;
}

if(ma==1&&ma==mi){
	cout<<n/2<<endl;
	return 0;
}
else if(ma<=1&&mi>=0){
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else{
				if(a[i+1]==1){
				ans++;
				i=i+1;	
				}
			}
		}
		cout<<ans;
	}
	return 0;	
}
else if(n<=1000){
	int now=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
		//cout<<i<<' '<<a[i]<<' '<<s[i]<<endl;
		if(a[i]==k){
//cout<<i<<' '<<s[i]<<endl;
			ans++;
			s[i]=0;
			now=i+1;
			continue;
		}
		for(int j=now;j<i;j++){
			if((s[j-1]^s[i])==k){
//cout<<i<<' '<<s[i]<<endl;
			ans++;
			s[i]=0;
			now=i+1;
			break;	
			} 
		}
	//	cout<<i<<' '<<s[i]<<endl;
	}
	cout<<ans;
	return 0;
}




int ans=0,now=0;
for(int i=1;i<=n;i++){
	mp[i]=mp[i-1];
	mp[i][0]=1;
	s[i]=s[i-1]^a[i];
	int l=k^s[i];
	if(mp[i][l]!=0){
//		cout<<i<<' '<<(k^a[i])<<' '<<mp[i][(k^a[i])]<<endl;
		ans++;
		s[i]=0;
		mp[i].clear();
	}
	else{
		s[i]=s[i-1]^a[i];
		mp[i][s[i]]++;
}
}

cout<<ans;

	
	
	return 0;
}
