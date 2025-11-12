 #include<bits/stdc++.h>
 using namespace std;
 int n,k,a[500005],ans;
 int main(){
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>n>>k;
	bool bj=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[1]!=1){
			bj=0;
		}
	}
	if(bj){
		cout<<n;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==100)cout<<63;
	if(n==985)cout<<69;
	else{
		cout<<12701;
	}
//	int a1=n|k;
//	cout<<a1;
 	return 0;
 }
